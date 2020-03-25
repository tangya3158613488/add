-- 库的相关操作
-- 查看已有库
SHOW DATABASES;
SHOW DATABASES\G

-- 新建库的操作 
CREATE DATABASE `class5051`;

-- 查看建库信息
SHOW CREATE DATABASE `class5051`;

-- 把一个库设置为默认库
USE class5051;

-- 删除库
DROP DATABASE class5051;


-- 表相关操作
-- 建表
CREATE TABLE students (
	id INT,
	name VARCHAR(30),
	idcard CHAR(18)
);

-- 查看有默认库下有哪些表
SHOW TABLES;

-- 查看建表信息
SHOW CREATE TABLE students;
DESC students;

-- 删表
DROP TABLE students;

-- 修改表名称
RENAME TABLE students TO class5051_students;

-- 插入数据
INSERT INTO students (id, name) VALUES
(18, "张三"); 

-- 修改数据
UPDATE students SET name = '李四' WHERE id = 18;

-- 查询
SELECT * FROM students WHERE name = '张三';

-- 删除
DELETE FROM students WHERE name = '李四';