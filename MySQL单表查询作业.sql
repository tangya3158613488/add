create database My_db;
use My_db;
1.员工表
create table employee (
employeeid char(3) unsigned primary key not null comment '员工编号',
name varchar(10) not null comment '姓名',
gender enum('男','女') default '女' not null comment '性别',
maritalstatus enum('是','否') comment '婚否',
employeetime date not null comment '聘用日期',
Email varchar(128)  comment '邮件',
photo varchar(255) not null comment '照片',
resume varchar(255) comment '简历'
)ENGINE=InnoDB DEFAULT CHARSET=utf8;

2.商品表
create table goods (
id char(6) unsigned primary key not null comment '商品编号',
brand varchar(20) not null comment '品牌',
category varchar(12) not null comment '类别',
mosel varchar(30) not null comment '型号',
goodsintroduce varchar(255) comment '商品介绍',
purchaseprice decimal(10,2) comment '进价',
sellprice decimal(10,2) comment '售价',
profitmargin decimal(4,2) comment '利润率'
)ENGINE=InnoDB DEFAULT CHARSET=utf8;
3.销售表
create table sale (
employeeid char(3) not null comment '员工编号',
goodsid char(6) not null comment '商品编号',
salesvolume int(5) not null comment '销售量',
salesdate timestamp default now() not null comment '销售日期',
foreign key (employeeid) references employee(employeeid),
foreign key (goodsid) references goods(id)
)ENGINE=InnoDB DEFAULT CHARSET=utf8;
4.设置员工表属性
alter table employee change id employeeid int(6); 	
gender enum('男','女') default '女' not null comment '性别';
alter table employee add phonenumber varchar(16);
alter table employee modify photo varchar(255) after phonenumber;
5.销售表设置属性

6.在“员工”表中输入如下记录
insert into employee (employeeid,name,gender,maritalstatus,employeetime,
Email,phonenumber,photo,resume) values
('001','王小萍','女','是','2007-05-10','wxp@sina.com','12345678',null,null),
('002','刘建军','男','是','2007-06-12','ljj@163.com',null,null,null),
('003','陈兰花','女','否','2007-11-20',null,'11223344',null,null),
('004','宋海波','男','否','2008-03-20','shb@yahoo.com',null,null,null),
('005','马海燕','女','否','2008-03-20',null,null,null,null),
('006','周涛','男','否','2008-09-22','zt@qq.com',null,null,null),
('007','李浩','女','是','2009-08-01','lh@qq.com',null,null,null),
('008','林慧慧','女','否','2009-12-25',null,null,null,null);

7.在“商品”表中输入如下记录
insert into goods(id,brand,category,mosel,purchaseprice,sellprice,profitmargin) values
('A00011','小天鹅','洗衣机','TB60-3073G',1005.60,1257.00,null),
('A00012','小天鹅','洗衣机','TB50-3073G',852.00,1048.00,null),
('A00013','小天鹅','洗衣机','XQB50-180G',842.00,1018.00,null),
('A00021','荣事达','洗衣机','RB55-3012G',830.40,1038.00,null),
('C00011','飞利浦','吸尘器','FC8641/01',1175.00,1350.00,null),
('C00031','伊莱克斯','吸尘器','ZS203',1000.00,1180.00,null),
('C00032','伊莱克斯','吸尘器','ZB2811',1248.00,1498.00,null),
('D00051','LG','微波炉','MG5337MKMR',670.00,760.00,null),
('D00061','格兰仕','微波炉','G8023CSL-K3',535.00,588.00,null);

8.在“销售”表中输入记录
insert into sale(employeeid,goodsid,salesvolume,salesdate)values
('001','A00011',1,'2007-10-1'),
('001','A00013',3,'2007-10-2'),
('002','A00021',5,'2007-10-2'),
('003','C00031',2,'2008-1-1'),
('002','A00011',2,'2008-1-1'),
('005','A00012',1,'2008-5-2'),
('001','A00011',3,'2008-7-12'),
('004','D00061',2,'2008-12-31'),
('006','D00061',5,'2009-1-3'),
('006','D00061',1,'2009-2-14'),
('002','A00013',3,'2009-10-1'),
('001','A00011',1,'2009-10-5'),
('006','D00051',3,'2009-3-15'),
('007','C00011',1,'2010-3-15'),
('004','D00051',2,'2010-5-2'),
('001','A00012',3,'2010-8-10');

 查询：
 1.select name,count(name) 
   from employee
   group by name having count(*)>1;
2.select id,brand,category,mosel,purchaseprice,sellprice 
  from goods
  where not exists
	(select id
	from goods,sale
	where goods.id=sale.goodsid);
3.select employeeid,name,gender,employeetime 
  from employee;
4.select employeeid,name,gender,employeetime
  from employee
  where gender='女'
  order by employeetime desc;
5.select employeeid,name,year(curdate())-year(employeetime) as workingage
  from employee;
6.select gender,count(*)
  from employee
  where gender in('男','女')
  group by gender;
7.select employee.employeeid,name,goodsid,salesvolume
  from employee,sale
  where employee.employeeid=sale.employeeid;
8.select sum(salesvolume) as sumnumber,sum(sellprice*salesvolume) as sumprice
  from sale,goods
  where goods.id=sale.goodsid
  group by goods.id;
9.select * from sale
  where 
10.select * from sale where goodsid like'D%';
11.select * from sale 
   where employeeid='001' or employeeid='003' or employeeid='005' 
   order by salesdate desc,employeeid;
12.//select goods.id,brand,category,sellprice,salesvolume,salesdate
   from goods,sale
   where goods.id=sale.goodsid 
   group by goods.category
   having sellprice<1200 and category<>'微波炉';
 13.select *
    from goods
	where sellprice>=1200 or brand='小天鹅';
14.create table maried as select * 
   from employee
   where gender='男' and maritalstatus='是';
15.alter table maried add butie decimal(8,1);
   update maried set butie=200;
   