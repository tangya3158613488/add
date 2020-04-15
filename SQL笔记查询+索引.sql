1. 基本查询
SELECT 			列的筛选
FROM 			表、多表、子查询
WHERE 			行的筛选
GROUP BY 		分组字段，可以有多个
HAVING 			在分组后的结果上，再次左行筛选
ORDER BY		结果排序
LIMIT 			最后切片

2. 聚合查询
COUNT(*)		最主要
MAX | MIN | SUM | AVG 

3. 分组（聚合）查询(***)
GROUP BY		可以多个字段分组，SELECT 后出现的只能是 GROUP BY 字段或者聚合函数
HAVING			所有的 HAVING 都可以转换为子查询的形式

4. 联/连表查询(***)	A	B
	1. 内联查询		（返回交集 A 交集 B）
		1. FROM A, B WHERE A.id = B.id;
		2. FROM A [INNER] JOIN B ON A.id = B.id;
	2. 外联查询
		1. 左联		返回以 A 为基准
		FROM A LEFT [OUTTER] JOIN B ON ...
		2. 右联		返回以 B 为基准
		FROM A RIGHT JOIN B ON ...
		3. 全联		A 并集 B	（MySQL 不支持）
5. 子查询
	所有子查询必须用小括号括起来
	1. WHERE 子句
		1. 结果是单行单列 
		2. 结果是多行单列 IN/ALL/ANY 
		3. 结果是单行多列 (字段1, 字段2, ...) = (子查询)	用 AND
	2. FROM 子句
		把结果看作临时表，再次查询
		1. 必须起别名
6. 联合查询
	1. UNION			会去重相同项
	2. UNION ALL



1. 索引（INDEX），用来提升查询效率的一类数据结构，保存在磁盘上。
2. 能提供搜索的功能的数据结构
	1. 平衡搜索树，B+树，应用较多
	2. 哈希表
3. 索引的工作原理
4. 为什么要用B+树，不用二叉搜索树
	1. B+树，是多叉树，所以同等情况下，高度更低
	2. 数据库文件保存在磁盘上，IO特别慢
	3. 高度越高，磁盘IO次数越多
5. 搜索树和哈希表的优缺点
	1. 搜索树		有序性
	2. 哈希表		快
	
	id, name, idcard		复合索引(name, idcard)
	1. 利用有序性
	SELECT * FROM 表 WHERE name > 'A' AND name < 'Z';	范围查找
	SELECT * FROM 表 ORDER BY name;						结果排序
	SELECT * FROM 表 ORDER BY name = 'xxx';
	2. 单个查找
	SELECT * FROM 表 WHERE name = 'A';
6. MySQL 支持的索引
	1. 主键
	2. 唯一键
	3. 普通索引	应用最多
	4. 全文索引（不支持中文）	Solr/Sphinx 搜索引擎	
7. 索引的优点和缺点
	1. 查找快
	2. 多耗空间 | 修改变慢
8. 索引的适用场景
	读多写少

CREATE TABLE students (
	id INT PRIMARY KEY,
	name CHAR(30),
	INDEX(name)
);

-- 查看一张表有的索引
SHOW INDEX FROM 表名;

-- 调优查询语句时用的，重要！！！	重点看 rows 列
EXPLIAN SELECT * FROM 表 WHERE name = 'A';

-- 如何调优查询
-- 1. 通过 EXPLAIN 看有没有命中索引
-- 2. 如果没有命中，修改到命中索引
	
	
	
	
	