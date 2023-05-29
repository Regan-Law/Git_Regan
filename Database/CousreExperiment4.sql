--实现不能对emp表中empno列的值进行编辑
create or replace trigger emp_no_update before
    update on emp
begin
    if updating('empno') then
        raise_application_error(-20000, '不能对emp表中empno列的值进行编辑');
    end if;
end;
/

update emp
set
    empno = 1
where
    empno = 7369;

--实现在晚24：00至次日凌晨2:00期间不能对emp表进行编辑
create or replace trigger emp_update before
    update on emp
begin
    if to_char(sysdate, 'hh24:mi:ss') between '24:00:00' and '02:00:00' then
        raise_application_error(-20000, '在晚24：00至次日凌晨2:00期间不能对emp表进行编辑');
    end if;
end;
/

--对奖金进行调整后，所有员工的总奖金不能超过50000元
create or replace trigger emp_sal_update before
    update on emp
begin
    if :new.sal > 50000 then
        raise_application_error(-20000, '对奖金进行调整后，所有员工的总奖金不能超过50000元');
    end if;
end;
/

--创建一个触发器实现：公司根据公司总的盈利情况将利润分配给各部门，规定：员工工资调整后，10部门所有员工的工资和不超过5000, 20部门所有员工的工资和不超过8000，30部门所有员工的工资和不超过20000，40部门所有员工的工资和不超过50000
create or replace trigger emp_sal_update before
    update on emp
begin
    if :new.deptno = 10 and :new.sal > 5000 then
        raise_application_error( -20000, '10部门所有员工的工资和不超过5000' );
    elsif :new.deptno = 20 and :new.sal > 8000 then
        raise_application_error(-20000, '20部门所有员工的工资和不超过8000');
    elsif :new.deptno = 30 and :new.sal > 20000 then
        raise_application_error(-20000, '30部门所有员工的工资和不超过20000');
    elsif :new.deptno = 40 and :new.sal > 50000 then
        raise_application_error(-20000, '40部门所有员工的工资和不超过50000');
    end if;
end;
/

--在emp表中添加“年收入”列，年收入为(sal+comm.)*12，创建触发器实现当调整sal或comm列的值后，自动更新“年收入”列的值
alter table emp add year_sal number(10, 2);

create or replace trigger emp_year_sal_update before
    update on emp
begin
    :new.year_sal := (:new.sal + :new.comm) * 12;
end;
/

--创建工资差额表，表名为diffsal,它包括工资排名前三名平均工资，所有员工平均工资，工资排名后三名平均工资
create table diffsal(
    top3_sal number(10, 2),
    all_sal number(10, 2),
    last3_sal number(10, 2)
);

--根据diffsal表，创建触发器，实现如下内容：如果调整emp表中的工资，便级联更新diffsal表中avgsal列中的值
create or replace trigger emp_diffsal_update before
    update on emp
begin
    update diffsal
    set
        top3_sal = (
            select avg(sal) from (select sal from emp order by sal desc) where rownum <= 3
        ),
        all_sal = (
            select avg(sal) from emp
        ),
        last3_sal = (
            select avg(sal) from (select sal from emp order by sal asc) where rownum <= 3
        );
end;
/

update emp
set
    sal = 5000
where
    empno = 7369;