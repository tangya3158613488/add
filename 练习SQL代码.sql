学生课程选课表
create table Student(
Sno int unsigned primary key comment '学号',
Sname varchar(20) not null comment '姓名',
Sdpartment varchar(20) not null comment '所属单位',
Sage int not null comment '年龄'
)ENGINE=InnoDB DEFAULT CHARSET=utf8;

create table Course(
Cno char(2) primary key not null comment'课程编号',
Cname varchar(30) not null comment'课程成绩'
)ENGINE=InnoDB DEFAULT CHARSET=utf8;
create table SC(
Sno int unsigned not null comment'学号',
Cno char(2) not null comment '课程编号',
Cgrade int not null comment'学习成绩'
)ENGINE=InnoDB DEFAULT CHARSET=utf8;

insert into Student(Sno,Sname,Sdpartment,Sage)values
(001,'钱一','D1',19),
(002,'陈二','D2',18),
(003,'张三','D3',20),
(004,'李四','D2',19),
(005,'王五','D4',22),
(006,'赵柳','D3',20),
(007,'田七','D5',21),
(008,'张晓丽','D4',22),
(009,'李伟','D5',20),
(010,'陈刚','D1',19);

insert into Course(Cno,Cname)values
('C1','高等数学'),('C2','大学英语'),('C3','网络原理'),('C4','信息管理'),('C5','管理信息系统'),('C6','大学英语'),('C7','创业基础');
insert into Sc(Sno,Cno,Cgrade)values
(001,01,80),(001,02,90),(001,03,78),(001,04,89),(001,05,97),(001,06,91);
insert into Course(Cno,Cname)values
(10,'基础税收'),(11,'数据库概论');
insert into SC(Sno,Cno,Cgrade)values
(002,'C1',60),(002,'C2',88),(003,'C1',66),(004,'C4',69),(003,'C4',81),
(007,'C5',72),(006,'C3',73),(003,'C7',87),(005,'C4',90),(003,'C5',83),
(003,'10',87),(004,'C5',77),(005,'C3',69),(006,10,84);

查询：
1.	查询选修课程名称为’税收基础’的学员学号和姓名（使用标准SQL嵌套语句）
2.	查询选修课程编号为’C2’的学员姓名和所属单位
3.	查询没有选修课程编号为’C5’的学员姓名和所属单位
4.	查询选修全部课程的学员姓名和所属单位（？？）
5.	查询选修了课程的学员人数
6.	查询选修课程超过5门的学员学号和所属单位

练习一：
1.select Sno,Sname
  from Student
  where Sno in
  (select Sno from SC
  where Cno in
  (select Cno from Course
  where Cname='税收基础'));
2.select Sname,Sdpartment
  from Student
  where Sno in
  (select Sno from SC
  where Cno='C2');
3.select Sname,Sdpartment
  from student
  where not exists
  (select * from SC
  where Sno=student.Sno and Cno='C5');
4.select Sname,Sdpartment
  from Student 
  where not exists
  (select * from Course
   where not exists
	(select * from SC 
	where Sno=Student.Sno and Cno=Course.Cno));
5.select count(distinct Sno) from SC;
6.select Sno,Sdpartment
  from Student
  where Sno in
  (select Sno
  from SC
  group by Sno
  having count(SC.Sno)>5);
  
  练习二：
  create table S(
  Sno int primary key not null comment '学号',
  Sname varchar(10) not null comment '姓名'
  )ENGINE=InnoDB DEFAULT CHARSET=utf8;
  
  create table C(
  Cno int primary key not null comment '课程号',
  Cname varchar(10) not null comment '课程名',
  Cteacher varchar(10) not null comment '任课教师'
  )ENGINE=InnoDB DEFAULT CHARSET=utf8;
  
  create table SC(
  Sno int primary key not null comment '学号',
  Cno int not null comment '课程号',
  SCgrade int comment '成绩',
  foreign key (Cno) references C(Cno)
  )ENGINE=InnoDB DEFAULT CHARSET=utf8;
  
  insert into S(Sno,Sname) values
  (1,'张三'),(2,'李四'),(3,'王五'),(4,'赵六'),(5,'田七');
  insert into C(Cno,Cname,Cteacher) values
  (1,'数学','李明'),(2,'语文','王欣'),(3,'数据库管理系统','赵亮'),(4,'C语言程序设计','孙武'),
  (5,'网络原理','刘佳');

  insert into SC(Sno,Cno,SCgrade)values
  (1,1,50),(2,2,80),(3,2,89),(4,3,95),(5,3,88),
  (1,4,56),(1,5,59),(3,3,79),(4,4,69),(2,1,80);
1．找出没有选修过“李明”老师讲授课程的所有学生姓名
2．	列出有二门以上（含两门）不及格课程的学生姓名及其平均成绩
3．	列出既学过“1”号课程，又学过“2”号课程的所有学生姓名
4．	列出比“Stu2”号同学的“Class1”号课成绩高的所有学生的学号、姓名

 1.	select Sname from S where not exist (
	select * from where not exists (
	select * from S(C where Sno=SC.Cno and CTEACHER='李明'));
2.	select Sname,avg(SCgrade) from SC,S group by Sno having avg(SCgrade)<60 and having count(*)>=2;
3.	select Sname from S,SC where S.Sno=SC.Sno and SC.Cno='1' and SC>Cno = '2';
4.  select Sno,Sname from S where Sno in(select Sno from SC where Sno<>2 and SCgrade >
	(select SCgrade from SC where Sno = 2 and Cno = 1));
  练习三：
  图书管理系统
1.create table card(
Cno char(3) primary key not null comment'卡号',
Name varchar(10) not null comment'姓名',
Class varchar(20) not null comment'班级'
)ENGINE=InnoDB DEFAULT CHARSET=utf8;
create table books(
Bno char(3)primary key not null comment'书号',
Name char(50) not null comment'书名',
Author varchar(30) not null comment'作者',
Price int unsigned not null comment'价格',
Quantity int unsigned not null comment'库存册数'
)ENGINE=InnoDB DEFAULT CHARSET=utf8;
create table borrow(
Cno char(3) not null comment'借书卡号',
Bno char(3) not null comment'书号',
Rdate datetime not null comment'还书日期',
foreign key(Bno) references books(Bno),
foreign key(Cno) references card(Cno),
primary key(Cno,Bno),
)ENGINE=InnoDB DEFAULT CHARSET=utf8;

insert into card(Cno,name,class)values
(101,'张三','C01'),(102,'李四','C02'),
(103,'王五','C01'),(104,'赵六','计本0801'),
(105,'李勇','计本0801'),(106,'王敏','C03'),(107,'张立国','C03');
insert into books(Bno,Name,Author,Price,Quantity)values
('A01','红楼梦','曹雪芹',30,10),
('A02','水浒','施耐庵',34,6),
('B01','计算方法','张小琴',20,8),
('B02','计算方法习题','李冬梅',29,3),
('C03','网络原理','王相林',50,7),
('C05','计算机网络','谢希仁',48,5),
('C04','C语言程序设计','谭浩强',37,2);
insert into borrow(Cno,Bno,Rdate)values
(101,'A01','2018-10-3'),
(102,'B01','2019-3-10'),
(103,'B02','2019-10-10'),
(101,'A02','2019-10-5'),
(101,'B02','2019-4-19'),
(101,'C03','2019-3-23'),
(101,'C05','2019-4-20'),
(101,'C04','2019-5-2');

  2.select Cno,count(Cno)
    from borrow
	group by Cno
	having count(Cno)>5;
  3.select NAME,CLASS
    from CARD
	where CNO in
	(select Cno from borrow
	where Bno in
	(select Bno from books
	where Name='水浒'));
  4.//select * from borrow where Rdate < now();
  5.select Bno,Name,Author
    from books
	where Name like'%网络' or Name like'网络%';
  6.select Name,Author
    from books where Price in (select max(Price) from books);
  7.select a.Cno from borrow a,books b where a.Bno = b.Bno
  and b.Name = '计算方法' and not exists (select * from borrow aa,books bb 
  where aa.Bno = bb.Bno and bb.Name = '计算机方法习题集' and aa.Cno = a.Cno)
  order by a.Cno desc;
  8.update borrow set Rdate = dateadd(day,7,borrow.Rdate)
  from card,borrow where card.Cno = borrow.Cno and card.Class = 'C01';
  9.delete from books where not exists(select * from borrow where Bno = books.Bno);
  10.create index idx_books_bname on books(Name);
  11.//create trigger tr_save on borrow for insert,update as 
  12.create view v_view as select card.Name,books.Name 
	from borrow,card,books
	where books.Cno = card.Cno and books.Bno = borrow.Bno and Class = '0801班';
  13.select borrow.Cno from books,borrow where books.Bno = borrow.Bno 
	and books.Name in('计算方法','组合数学') group by borrow.CnO
	having count(*) = 2 order by borrow.Cno desc;
  14.alter table books add primary key(Bno);
  15.1 alter table card alter column Name varchar(10);
  15.2 alter table card add department varchar(20);