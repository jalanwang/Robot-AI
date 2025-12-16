-- bmi = weight/(height*height*0.0001)
-- 단, 소숫점은 2자리 까지

select name, round(weight/(height*height*0.0001),2) as BMI from person

create view showBMI
AS
select name, round(weight/(height*height*0.0001),2) as BMI from person

select * from showBMI;

update person set height=99 where height is null;

SELECT
   substr('abcdefg', 3),      -- 셋째 자리부터 끝까지
   substr('abcdefg', 3, 2);  -- 셋째 자리부터 두 글자
-- orcle 에서는 dual을 넣어 주어야 한다.
-- select
-- 
--
-- from dual; 테이블을 임시로 만들고 가지고 온다.

create view birthdayview
AS
select
Name,
birthday as bdate,
substr(birthday,1,4) as YYYY,
substr(birthday,6,2) as MM,
substr(birthday,9,2) as DD
from person;

SELECT * FROM BirthdayView;

SELECT
    Name,
    bdate,
    MM,
    CASE
        WHEN MM = '01' THEN 'Jan.'
        WHEN MM = '02' THEN 'Feb.'
        WHEN MM = '03' THEN 'Mar.'
        WHEN MM = '04' THEN 'Apr.'
        WHEN MM = '05' THEN 'May.'
        WHEN MM = '06' THEN 'Jun.'
        WHEN MM = '07' THEN 'Jul.'      
        WHEN MM = '08' THEN 'Aug.'
        WHEN MM = '09' THEN 'Sep.'
        WHEN MM = '10' THEN 'Oct.'
        WHEN MM = '11' THEN 'Nov.'
        WHEN MM = '12' THEN 'Dec.'
        -- when MM = 'null' then 'Unknown' #작동안함
    END Month
FROM BirthdayView;

SELECT strftime('%Y-%m-%d %H:%M:%S', 'now')

-- 날짜를 다음과 같이 출력하려면?
-- 12/16 11:30

-- 만나이 구하기 1
-- SELECT 
--     NAME,
--     bdate,    
--     (strftime('%Y', 'now') - YYYY) AS 만나이
-- FROM BirthdayView;

-- 만나이 구하기 2
SELECT
    Name,
    birthday,
    cast(strftime('%Y', 'now') as integer) - cast(substr(birthday,1,4) as integer) as 만나이
FROM person;

-- 집게함수 시작
select count(*), max(height), min(height), avg(height) from Person

update person set height = null where id = 14
-- 일단 NULL로 변경후 테스트할게 있음.

update person set height=192.3 where id = 14

-- oracle, nvl
select name, ifnull(height, 0) from Person



-- group by
select round(height), count(*)
from Person
group by round(height)
having count(*)>=1;

CREATE TABLE employees (
    dept TEXT,
    job TEXT,
    salary INTEGER
);

INSERT INTO employees VALUES
('개발','백엔드',6000),
('개발','백엔드',6500),
('개발','프론트',5500),
('개발','프론트',5200),
('영업','영업사원',4000),
('영업','영업사원',4200),
('영업','팀장',7000),
('인사','인사담당',4500),
('인사','팀장',6000),
('인사','팀장',6200);

update person set height = null where id = 17;
select name, ifnull(height, 0) from person;

select * from employees;

select dept from employees;
select dept, salary from employees;


-- 급여가 5천 이상인 부서의  
select dept, round(avg(salary),0), max(salary), min(salary)
from employees
group by dept
having avg(salary) >= 5000; 

-- 직원이 3명이상인 부서는?
select dept, count(*)
from employees
group by dept -- where에는 집계함수는 사용할 수 업다.
having count(*) >= 3;

-- 직무별 평균급여가 6천이상인 직무는?

select job, round(avg(salary),0)
from employees
group by job
having avg(salary) >= 6000;



---------------------- 교재
CREATE TABLE 노래 (
  ID INTEGER NOT NULL PRIMARY KEY,
  제목 TEXT NOT NULL
);

CREATE TABLE 음반 (
  ID INTEGER NOT NULL PRIMARY KEY,
  제목 TEXT NOT NULL,
  연도 INTEGER
);

CREATE TABLE 수록곡 (
  음반ID INTEGER NOT NULL,
  노래ID INTEGER NOT NULL
);

INSERT INTO 노래 VALUES
(1, '갸우뚱'),
(2, 'Shuppy Shuppy'),
(3, 'Control'),
(4, '영러브'),
(5, '한번만 안아줘'),
(6, '반짝반짝'),
(7, '기대해'),
(8, 'I Don''t Mind'),
(9, 'Easy go'),
(10, '여자대통령');

INSERT INTO 음반 VALUES
(1, 'Girl''s Day Party #1', 2010),
(2, 'Everyday', 2011),
(3, 'Expectation', 2013),
(4, '여자대통령', 2013);

INSERT INTO 수록곡 VALUES 
(1, 1),
(1, 2),
(1, 3),
(2, 4),
(2, 5),
(2, 6),  -- Everyday - 반짝반짝
(3, 7),
(3, 8),
(3, 9),
(3, 6),  -- Expectation - 반짝반짝
(3, 5),
(4, 10);

SELECT 음반.제목 앨범명, 음반.연도 발매년도, 노래.제목 곡명
FROM 수록곡
JOIN 음반 ON 수록곡.음반ID = 음반.ID
JOIN 노래 ON 수록곡.노래ID = 노래.ID


-----------------------
DROP TABLE IF EXISTS enrollment;
DROP TABLE IF EXISTS student;
DROP TABLE IF EXISTS course;

CREATE TABLE student (
    id    INTEGER PRIMARY KEY,
    name  TEXT NOT NULL,
    major TEXT NOT NULL,
    year  INTEGER NOT NULL
);

CREATE TABLE course (
    id       INTEGER PRIMARY KEY,
    title    TEXT NOT NULL,
    category TEXT NOT NULL,
    credit   INTEGER NOT NULL
);

CREATE TABLE enrollment (
    id         INTEGER PRIMARY KEY AUTOINCREMENT,
    student_id INTEGER NOT NULL,
    course_id  INTEGER NOT NULL,
    semester   TEXT NOT NULL,
    grade      TEXT,

    FOREIGN KEY (student_id) REFERENCES student(id),
    FOREIGN KEY (course_id)  REFERENCES course(id),

    UNIQUE(student_id, course_id, semester)
);

-- 데이터 삽입
INSERT INTO student VALUES
(1, '김민수', '컴퓨터공학', 1),
(2, '이서연', '컴퓨터공학', 2),
(3, '박지훈', '컴퓨터공학', 3),
(4, '최유진', '컴퓨터공학', 4),

(5, '정우성', '전자공학', 1),
(6, '한지민', '전자공학', 2),
(7, '오세훈', '전자공학', 3),
(8, '신하늘', '전자공학', 4),

(9, '장민지', '기계공학', 1),
(10,'임도윤', '기계공학', 2),
(11,'서준호', '기계공학', 3),
(12,'윤채원', '기계공학', 4),

(13,'강민혁', '산업공학', 1),
(14,'문지아', '산업공학', 2),
(15,'백승우', '산업공학', 3),
(16,'조수빈', '산업공학', 4),

(17,'홍준표', '컴퓨터공학', 2),
(18,'김하린', '전자공학', 3),
(19,'이도현', '기계공학', 4),
(20,'박소연', '산업공학', 1);

INSERT INTO course VALUES
(1, 'C 프로그래밍',        '프로그래밍', 3),
(2, 'C++ 객체지향',        '프로그래밍', 3),
(3, 'Python 기초',         '프로그래밍', 3),
(4, '자료구조',            '프로그래밍', 3),

(5, '데이터베이스 기초',   'DB',         2),
(6, 'SQL 활용',            'DB',         3),

(7, '임베디드 시스템',     '임베디드',   3),
(8, 'ROS 입문',            '로봇',       3),

(9, '머신러닝 기초',       'AI',         3),
(10,'산업공학 개론',       '이론',       2);

INSERT INTO enrollment (student_id, course_id, semester, grade) VALUES
(1, 1, '2025-1', 'A0'),
(1, 5, '2025-1', 'B+'),

(2, 2, '2025-1', 'A+'),
(2, 6, '2025-1', 'A0'),

(3, 4, '2025-1', 'B0'),
(3, 9, '2025-1', 'A0'),

(4, 8, '2025-1', 'A0'),

(5, 7, '2025-1', 'A0'),
(6, 3, '2025-1', 'B+'),

(7, 6, '2025-1', 'A0'),
(8, 2, '2025-1', 'B+'),

(9, 10,'2025-1', 'A0'),
(10,5, '2025-1', 'B+'),

(11,9, '2025-1', 'A+'),
(12,4, '2025-1', 'B0'),

(13,6, '2025-1', 'A0'),
(14,1, '2025-1', 'B+'),

(15,2, '2025-1', 'A0'),
(16,8, '2025-1', 'A+'),

(17,9, '2025-1', 'B0'),
(18,7, '2025-1', 'A0'),

(19,4, '2025-1', 'B+'),
(20,10,'2025-1', 'A0');

select * from student;
select * from course;
select * from enrollment;   

select s.name, c.title, e.grade 
from enrollment e
join student s on e.student_id = s.id
join course c on e.course_id = c.id;

-- 특정 학생의 수강 과목을 알고 싶다???? [학생이름] [과목이름] [성적]

select s.name, c.title, e.grade 
from enrollment e
join student s on e.student_id = s.id
join course c on e.course_id = c.id
where s.name = '김민수';

-- 특정 과목을 수강한 학생의 이름과 성적? [과목이름] [학생이름] [성적] - c 프로그래밍 / id=1

select c.title, s.name, e.grade
from enrollment e
join student s on e.student_id = s.id
join course c on e.course_id = c.id
where c.id = 2;

-- 학과별 수강 건수는?
select s.major, count(*) as 수강건수
from enrollment e
join student s on e.student_id = s.id
group by s.major
