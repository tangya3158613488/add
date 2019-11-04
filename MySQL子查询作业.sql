1.职工信息表
create table employee(
id char(4) primary key comment '职工编号',
name varchar(10) comment '姓名',
sex char(1) check(sex in('男','女')),
borndate date comment '出生年月',
department char(10) comment '工作部门',
positionaltitles char(2) comment '职称'
)ENGINE=InnoDB DEFAULT CHARSET=utf8;
2.工资标准表
create table wagestandards(
positionaltitles char(2) primary key comment '职称',
wagestandards int comment '工资标准'
)ENGINE=InnoDB DEFAULT CHARSET=utf8;
4.考勤表
create table attendance(
id char(4) primary key comment '职工编号',
sickdays int comment '病假天数',
leavedays int comment '事假天数',
overworkdays int comment '加班天数'
)ENGINE=InnoDB DEFAULT CHARSET=utf8;
insert into employee(id,name,sex,borndate,department,positionaltitles) values
('0902','张骞','男','1979-8-9','人事部','高级'),('0903','田佳','女','1971-9-3','市场部','初级'),
('0904','姜茸','女','1982-8-2','后勤部','中级'),('0906','吴越','男','1983-4-8','安全部','初级'),
('0907','马南','女','1980-8-6','人事部','中级'),('0908','简里','男','1977-8-4','市场部','中级'),
('0909','王月茹','女','1988-8-2','后勤部','中级'),('0910','左丞','男','1982-4-8','安全部','初级'),
('0911','花月华','女','1983-8-6','人事部','中级'),('0912',null,'男','1976-8-4','后勤部','中级');

insert into wagestandards(positionaltitles,wagestandards)values
('高级',5000),('中级',3500),('初级',2000);

insert into attendance(id,sickdays,leavedays,overworkdays)values
('0902',3,0,2),('0903',0,0,0),('0904',0,0,1),('0906',0,0,0),
('0907',6,7,0),('0908',4,8,2),('0909',6,4,8),('0910',0,0,0);

3.工资表
create table dolar as 
select id,wagestandards.positionaltitles,wagestandards as wage 
from employee,wagestandards
where employee.positionaltitles = wagestandards.positionaltitles;
添加主键：
alter table dolar add primary key (id);
添加外键:
alter table dolar add constraint fk foreign key (positionaltitles) references wagestandards(positionaltitles);
4.update dolar set wage = wage*1.5 
  where id in( select id from employee
  where year(curdate())-year(borndate)>30);
5.select name,employee.positionaltitles,dolar.wage
  from employee,dolar
  where employee.department = '后勤部' and employee.id = dolar.id
  order by year(curdate())-year(borndate) desc;
6.select count(*) as employeenum from employee 
  where positionaltitles = '中级';
  
  select name as maxagename
  from employee where positionaltitles = '中级' and year(curdate())-year(borndate)=
  (select max(year(curdate())-year(borndate)) 
  from employee where positionaltitles = '中级');
  
7.update dolar,attendance set
 wage = wage+overworkdays*wage*0.03-sickdays*wage*0.01-leavedays*wage*0.02
 where dolar.id = attendance.id;
 
 //8.select *from employee x
 where x.positionaltitles <> '后勤部' and x.borndate < (select min(borndate)
 from employee where positionaltitles = '后勤部');
 and 
 9.select name,wage from dolar,employee where dolar.id = employee.id and department in
 (select department from employee where name = '张骞');
 10.delete from employee where positionaltitles = '后勤部' cascade;
 