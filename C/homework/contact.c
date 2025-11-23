//주소록 만드는 프로그램
//helper: copilot agent

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* maximum contacts kept in memory / saved to file */
#define MAX_CONTACTS 100

/* forward declarations */
void contact_list(const char* file);
int load_contacts(const char* file);
int save_contacts(const char* file);
void contact_insert(const char* file);
void contact_modify(const char* file);
void contact_delete(const char* file);

typedef struct Namecard {
    char name[20];
    char phone[20];
    char company[50];
    char email[50];
    char info[100];
} namecard; 

enum func {
    list=1, insert, modify, delete, terminate };

/* in-memory contacts */
static namecard *contacts = NULL;
static int contact_count = 0;
static int contacts_loaded = 0;

/*
 * 프로그램 동작 요약:
 * - 연락처는 먼저 메모리(동적 배열 `contacts`)로 관리됩니다.
 * - `contact_list`가 호출되면 아직 메모리에 로드되지 않은 경우 파일에서 로드합니다.
 * - `contact_insert`는 메모리에 새 항목을 추가하고, 실제 파일 쓰기는
 *   사용자 선택(현재는 메뉴 5: 저장 후 종료)에서 한 번에 수행됩니다.
 * - 이 설계는 입력/수정 작업을 메모리에서 빠르게 처리한 뒤
 *   프로그램 종료 시 일괄 저장하는 패턴을 따릅니다.
 */

/* load contacts from file into memory; returns number of contacts or -1 on error */
int load_contacts(const char* file)
{
    FILE *fp = fopen(file, "r");
    if (!fp) return 0; /* treat missing file as empty list */

    char line[512];
    while (fgets(line, sizeof line, fp)) {
        if (line[0] == '\n' || line[0] == '\0') continue;
        line[strcspn(line, "\r\n")] = '\0'; //string complementary span

        if (contact_count >= MAX_CONTACTS) {
            /* reached storage limit, ignore remaining lines */
            printf("경고: 최대 연락처 수(%d) 도달 - 나머지 항목은 무시됩니다.\n", MAX_CONTACTS);
            break;
        }

        /*
         * 파싱(구분자 '|') 설명:
         * - 파일의 한 라인은 `이름|전화|회사|이메일|추가정보` 형식으로 저장되어 있다고 가정합니다.
         * - 여기서는 C의 `strtok`을 사용해 '|'로 분리합니다.
         * - `strtok(line, "|")`은 입력 문자열 `line`을 변경(토큰 경계를 '\0'으로 바꿈)하며
         *   첫 번째 토큰의 포인터를 반환합니다. 이후 호출은 `strtok(NULL, "|")`로 이어갑니다.
         * - `strtok`은 원본 문자열을 파괴하므로 원본 보존이 필요하면 복사본을 만들어야 합니다.
         * - `strtok`은 전역 상태를 사용하므로 다중 스레드/중첩 파싱에는 부적합합니다.
         *   (필요하면 `strtok_r`을 사용하세요.)
         */
        namecard nc = {0};
        char *p = strtok(line, "|");
        if (p) strncpy(nc.name, p, sizeof nc.name-1);

        /* 다음 토큰(전화번호) */
        p = strtok(NULL, "|");
        if (p) strncpy(nc.phone, p, sizeof nc.phone-1);

        /* 다음 토큰(회사) */
        p = strtok(NULL, "|");
        if (p) strncpy(nc.company, p, sizeof nc.company-1);

        /* 다음 토큰(이메일) */
        p = strtok(NULL, "|");
        if (p) strncpy(nc.email, p, sizeof nc.email-1);

        /* 다음 토큰(추가정보) */
        p = strtok(NULL, "|");
        if (p) strncpy(nc.info, p, sizeof nc.info-1);

        // 연락처 배열(contacts)에 새 항목을 추가하기 위해 메모리를 재할당합니다.
        // realloc은 기존 contacts 포인터의 메모리 크기를 (contact_count + 1) * sizeof *contacts로 늘립니다.
        // 만약 메모리 부족 등으로 재할당에 실패하면 NULL을 반환합니다.
        namecard *tmp = realloc(contacts, (contact_count + 1) * sizeof *contacts); 
        if (!tmp) {
            // 재할당 실패 시, 파일을 닫고 -1을 반환하여 호출자에게 오류를 알립니다.
            // 기존 contacts 포인터는 그대로 유지되며, 메모리 누수는 발생하지 않습니다.
            fclose(fp);
            return -1; /* allocation error */
        }
        contacts = tmp;
        contacts[contact_count++] = nc;
    }

    fclose(fp);
    contacts_loaded = 1;
    return contact_count;
}

/* save contacts from memory to file; returns 0 on success, -1 on error */
int save_contacts(const char* file)
{
    FILE *fp = fopen(file, "w");
    if (!fp) return -1;

    for (int i = 0; i < contact_count; ++i) {
        fprintf(fp, "%s|%s|%s|%s|%s\n",
                contacts[i].name,
                contacts[i].phone,
                contacts[i].company,
                contacts[i].email,
                contacts[i].info);
    }

    fclose(fp);
    return 0;
}

/* helper: read a full line from stdin into buf, strip trailing newline */
static void read_input_line(char *buf, size_t size)
{
    if (fgets(buf, size, stdin) == NULL) {
        buf[0] = '\0';
        return;
    }
    buf[strcspn(buf, "\r\n")] = '\0';
}

int main()
{
    enum func menu;
    (void)0; /* previously used variable removed; menu input uses read_input_line */

    while(1) {
        printf("\n=============================\n");
        printf("   미니 명함 관리 프로그램\n");
        printf("=============================\n");
        printf("1. 명함 목록 보기\n");
        printf("2. 명함 추가\n");
        printf("3. 명함 수정(추후에)\n");
        printf("4. 명함 삭제(추후에)\n");
        printf("5. 저장 후 종료\n");
        printf("----------------------\n");
        printf("메뉴를 선택하세요: ");

        /* 메뉴 선택: fgets 기반으로 통일하여 입력 혼용 문제(남은 개행 등)를 방지합니다 */
        char selbuf[32];
        read_input_line(selbuf, sizeof selbuf);
        if (selbuf[0] == '\0') continue;
        char *endptr = NULL;
        long val = strtol(selbuf, &endptr, 10);
        if (endptr == selbuf || *endptr != '\0') continue;
        menu = (int)val;

        switch(menu) {
            case list:
                contact_list("./businesscard.txt");
            break;

            case insert:
                contact_insert("./businesscard.txt");
            break;

            case modify:
                contact_modify("./businesscard.txt");
            break;

            case delete:
                contact_delete("./businesscard.txt");
            break;

            case terminate:
            /* save contacts to file before exiting */
            if (save_contacts("./businesscard.txt") < 0) {
                printf("저장중 오류가 발생했습니다. 강제 종료합니다.\n");
            } else {
                printf("저장 완료. 프로그램을 종료합니다.\n");
            }
            exit(0);
        }                 
    }

    return 0;
}

void contact_list(const char* file)
{
    /* ensure contacts are loaded into memory */
    if (!contacts_loaded) {
        if (load_contacts(file) < 0) {
            printf("파일을 읽어올 수 없습니다.\n");
            return;
        }
    }

    printf("[명함 목록]\n\n");
    printf("번호  이름       전화번호        회사             이메일                 추가정보\n");
    printf("-------------------------------------------------------------------------------\n");

    for (int no = 0; no < contact_count; ++no) {
        printf("%-4d %-10s %-15s %-15s %-20s %s\n",
               no,
               contacts[no].name,
               contacts[no].phone,
               contacts[no].company,
               contacts[no].email,
               contacts[no].info);
    }

}

void contact_insert(const char* file)
{
    (void)file; /* parameter unused: function appends to in-memory list */
    namecard nc = {0};

    if (contact_count >= MAX_CONTACTS) {
        printf("연락처는 최대 %d개까지만 저장할 수 있습니다.\n", MAX_CONTACTS);
        return;
    }

    /* fgets 기반 입력 처리: main에서 메뉴 입력도 fgets 계열로 통일했으므로
     * 여기서 별도의 입력 플러시가 필요하지 않습니다.
     */
    printf("이름: ");
    read_input_line(nc.name, sizeof nc.name);
    printf("전화번호: ");
    read_input_line(nc.phone, sizeof nc.phone);
    printf("회사명: ");
    read_input_line(nc.company, sizeof nc.company);
    printf("이메일: ");
    read_input_line(nc.email, sizeof nc.email);
    printf("기타정보: ");
    read_input_line(nc.info, sizeof nc.info);

    namecard *tmp = realloc(contacts, (contact_count + 1) * sizeof *contacts);
    if (!tmp) {
        printf("메모리 할당 실패: 연락처를 추가할 수 없습니다.\n");
        return;
    }
    contacts = tmp;
    contacts[contact_count++] = nc;
    contacts_loaded = 1;

    printf("연락처가 메모리에 추가되었습니다. (메뉴 5에서 저장됩니다.)\n");
}

/* modify an existing contact in memory */
void contact_modify(const char* file)
{
    if (!contacts_loaded) {
        if (load_contacts(file) < 0) {
            printf("파일을 읽어올 수 없습니다.\n");
            return;
        }
    }

    if (contact_count == 0) {
        printf("편집할 연락처가 없습니다.\n");
        return;
    }

    /* show current list with numbers */
    contact_list(file);

    printf("수정할 연락처 번호를 입력하세요: ");
    char buf[32];
    read_input_line(buf, sizeof buf);
    if (buf[0] == '\0') {
        printf("입력이 취소되었습니다.\n");
        return;
    }

    char *endptr = NULL;
    long idxl = strtol(buf, &endptr, 10);
    if (endptr == buf || *endptr != '\0') {
        printf("유효한 숫자를 입력하세요.\n");
        return;
    }
    int idx = (int)idxl;
    if (idx < 0 || idx >= contact_count) {
        printf("유효하지 않은 번호입니다.\n");
        return;
    }

    namecard *t = &contacts[idx];

    printf("현재 이름: %s\n새 이름(빈칸 입력시 유지): ", t->name);
    read_input_line(buf, sizeof buf);
    if (buf[0] != '\0') strncpy(t->name, buf, sizeof t->name-1);

    printf("현재 전화번호: %s\n새 전화번호(빈칸 입력시 유지): ", t->phone);
    read_input_line(buf, sizeof buf);
    if (buf[0] != '\0') strncpy(t->phone, buf, sizeof t->phone-1);

    printf("현재 회사: %s\n새 회사명(빈칸 입력시 유지): ", t->company);
    read_input_line(buf, sizeof buf);
    if (buf[0] != '\0') strncpy(t->company, buf, sizeof t->company-1);

    printf("현재 이메일: %s\n새 이메일(빈칸 입력시 유지): ", t->email);
    read_input_line(buf, sizeof buf);
    if (buf[0] != '\0') strncpy(t->email, buf, sizeof t->email-1);

    printf("현재 추가정보: %s\n새 추가정보(빈칸 입력시 유지): ", t->info);
    read_input_line(buf, sizeof buf);
    if (buf[0] != '\0') strncpy(t->info, buf, sizeof t->info-1);

    printf("연락처가 수정되었습니다. (메뉴 5에서 저장됩니다.)\n");
}

/* delete an existing contact from memory */
void contact_delete(const char* file)
{
    if (!contacts_loaded) {
        if (load_contacts(file) < 0) {
            printf("파일을 읽어올 수 없습니다.\n");
            return;
        }
    }

    if (contact_count == 0) {
        printf("삭제할 연락처가 없습니다.\n");
        return;
    }

    /* show current list with numbers */
    contact_list(file);

    printf("삭제할 연락처 번호를 입력하세요: ");
    char buf[32];
    read_input_line(buf, sizeof buf);
    if (buf[0] == '\0') {
        printf("입력이 취소되었습니다.\n");
        return;
    }

    char *endptr = NULL;
    long idxl = strtol(buf, &endptr, 10);
    if (endptr == buf || *endptr != '\0') {
        printf("유효한 숫자를 입력하세요.\n");
        return;
    }
    int idx = (int)idxl;
    if (idx < 0 || idx >= contact_count) {
        printf("유효하지 않은 번호입니다.\n");
        return;
    }

    /* confirm deletion */
    printf("정말로 연락처 #%d (%s) 를 삭제하겠습니까? (y/N): ", idx, contacts[idx].name);
    read_input_line(buf, sizeof buf);
    if (!(buf[0] == 'y' || buf[0] == 'Y')) {
        printf("삭제가 취소되었습니다.\n");
        return;
    }

    /* shift remaining elements down */
    if (idx < contact_count - 1) {
        memmove(&contacts[idx], &contacts[idx+1], (contact_count - idx - 1) * sizeof *contacts);
    }
    contact_count--;

    if (contact_count == 0) {
        free(contacts);
        contacts = NULL;
        contacts_loaded = 0;
    } else {
        namecard *tmp = realloc(contacts, contact_count * sizeof *contacts);
        if (tmp) contacts = tmp; /* ignore realloc failure, keep larger block */
    }

    printf("연락처가 삭제되었습니다. (메뉴 5에서 저장됩니다.)\n");
}
