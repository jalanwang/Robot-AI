-- 5.1 Person 테이블을 나이가 많은 사람이 먼저 오도록 정렬해서 조회해보라.
-- 생일을 알 수 없는 사람은 제외한다.
select * from Person where birthday is not null order by Birthday  desc

-- 5.2 Person 테이블에서 Name이 김으로 시작하는 행을 찾아서, 그 값을 유라로 바꾸어 보라.
UPDATE Person SET Name = '김유라' WHERE Name LIKE '김%';

-- 5.3 연습문제 3.1에서 만든 pets 테이블에 다음과 같이 데이터를 넣어라.

insert into pets values (1,'Dr. Harris Bonkers', 'Rabbit');
insert into pets values (2,'Moon', 'Dog');
insert into pets values (3,'Ripley', 'Cat');
insert into pets values (4,'Tom', 'Cat')

-- 연습문제
-- 3.1 다음과 같은 열을 갖는 pets 테이블을 만들어보라.
-- Name	Type	NN	PK	AI	U	Default	Check
-- ID	INTEGER	✓	✓				
-- Name	TEXT	✓					
-- Animal	TEXT	✓					

