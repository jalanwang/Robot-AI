-- 1. 테이블 작성(Addressbook)
-- ID(PK, NN, AI), NAME, PNUMBER
-- 2. 데이터 삽입
   -- 10. 홍길동 000-0000-0000
   -- 20. 이순신 000-1111-0000
   -- 30. 강감찬 000-2222-0000
-- 삭제
    -- 강감찬 장군 삭제 ID로 해보세요~!


-- 삽입
INSERT INTO Addressbook VALUES (10, '홍길동', '000-0000-0000' );
-- 삽입
INSERT INTO Addressbook VALUES (20, '이순신', '000-1111-0000');
-- 삽입
INSERT INTO Addressbook VALUES (30, '강감찬', '000-2222-0000');

-- 업데이트
UPDATE Addressbook SET NAME='김길동' WHERE ID = 10;

-- 삭제
-- DELETE FROM Addressbook; 전체삭제
DELETE FROM ADDRESSBOOK WHERE ID=30