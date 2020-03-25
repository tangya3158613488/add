-- 1. 理论
-- 		1. 了解什么是 MySQL
-- 		2. 常见的数据库
--		3. SQL 结构化查询语言
--			1. DDL		其次，实际工作中，往往是 DBA 来建库建表
--			2. DML		使用的重点，增删改查
--			3. DCL		DBA 在用
--		4. 字符集编码
--			Unicode
--				1. GB18030（GBK/GB2312）		（英语+汉语）
--				2. UTF-8						（全支持）
--					utf8
--		5. 服务(TCP 3306) - 库(DB Database) - 表(Table)
--				1. 库 想象成一个应用，项目
-- 				2. 表 一个类
--				3. 列 类的一个成员变量
--				4. 行 这个类的具体对象
--		6. 表和表之间的关系
--			1. 一对一的关系
--			2. 一对多的关系
--			3. 多对多的关系
-- 2. 操作
--		0. 登陆 mysql		mysql -u<mysql 的用户名> -p
-- 		1. DDL
--			1. 库
--				1. CREATE DATABASE 库名;
--				2. SHOW DATABASES;
--				3. SHOW CREATE DATABASE 库名;
--				4. USE 库名;
--				5. DROP DATABASE 库名;
--			2. 表
--				1. CREATE TABLE 表名 (列名 列类型, ..., 列名 列类型);
--				2. SHOW TABLES;
--				3. SHOW CREATE TABLE 表名; DESC 表名;
--				4. DROP TABLE 表名;
--				5. RENAME TABLE 旧表名 TO 新表名;

/*
 整型
	1. 常用		
		1. 整型 TINYINT,SMALLINT,INT,BIGINT
		2. 小数
			1. 浮点数（不是高精度）	FLOAT/DOUBLE
			2. 保证精度				DECIMAL/NUMEROUS
		3. 坑
			1. bit 显式的时候是 ASCII 码
			2. CHAR 最多 255 个字符
			3. VARCHAR 最多是 65535 个字节，具体多少字符
							65535/3(每个utf8 占 3 字节)
		4. 字符类型
			1. 定长		CHAR(字符个数)
			2. 变长		VARCHAR(字符个数)
			3. TEXT 	字符
			4. BLOB		字节流
		5. 日期、时间
			1. DATETIME		年-月-日 时:分:秒
			2. DATE			年-月-日
			3. TIME			时:分:秒
			4. TIMESTAMP	时间戳(1970 的秒数)
			
			TIMESTAMP vs DATETIME
			4 个字节 	 8 个字节
			1970 - 2037	 0000-9999
		6. MySQL 规范上不建议使用 ENUM 和 SET
			1. 修改表结构的代价非常大
			2. ENUM/SET 信息保存在表结构中
			3. 所以，更新 ENUM 及 SET 都需要修改表结构，风险较大
			4. 所以不建议使用
		7. 带括号的数据类型
			1. CHAR(字符个数，会影响字段长度)
			2. VARCHAR(字符个数，会影响字段长度)
			3. BIT(位的长度，会会影响字段长度)
			4. FLOAT(整体的显式位数，小数点后显式位数；不影响字段长度)
			5. INT(显式长度，不影响字段长度)	ZEROFILL
			
			INT(10)	存了一个 3		0000000009 只在 mysql 命令行有效
*/

/*
	NULL 不区分大小写
	NULL 的真实含义时，这个字段值不知道
	所以一般来说，有 NULL 参与的运算结果都是 NULL
	定义表时，字段后可以跟 NOT NULL 强制不允许出现空
	没有特殊理由，建议都加上 NOT NULL
*/

/*
	DEFAULT 后跟 默认值
*/

/*
	1. 主键，每个信息都有主键，用来唯一标识一条信息
	可以是一个字段，可以是多个字段组成（复合主键）
	
	2. 在 InnoDB 的引擎下，数据在硬盘存储是按照主键的排序方式存储的
		为了避免中间插入主键，通常建议把主键设置成一个
			1. 永远递增
			2. 永不修改
		的值
	3. 主键不允许为空/主键不允许重复
	4. 每个表上都有一个主键，通常用自增字段作为主键
*/

/*
唯一键 Unique Key
相似的点：
1 主键和唯一键都不允许重复
不同点：
1. 主键不允许为空，唯一键允许为空
2. 存储上，数据的存储是按照 主键 递增顺序保存的
   唯一键，看作另外有一套数据结构
*/

CREATE TABLE students (
	id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT COMMENT "利用自增字段作为表主键",
	sn INT NOT NULL UNIQUE COMMENT "学号，事实上的主键，唯一键，不允许重复",
	name VARCHAR(10) NOT NULL COMMENT "姓名",
	gender TINYINT NOT NULL COMMENT "性别: 1 女  2 男 3 不想说",
	school VARCHAR (40) NOT NULL DEFAULT "XXX大学" COMMENT "学校",
	registerd_at DATETIME NOT NULL COMMENT "报名时间",
	created_at TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT "入表时间"
) COMMENT "学生表";

CREATE TABLE students (
	...
	PRIMARY KEY (id, sn)		-- 支持单字段 或者 多字段
	UNIQUE KEY (sn, name)
)



 	

,


