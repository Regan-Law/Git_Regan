--从emp表中找出30号部门人数和工资总和
create or replace procedure count_emp1 as
    sal_sum   number;
    count_emp number;
begin
    select
        count(*),
        sum(sal) into sal_sum,
        count_emp
    from
        emp
    where
        deptno = 30;
    dbms_output.put_line('30号部门人数为：'
        || count_emp);
    dbms_output.put_line('30号部门工资总和为：'
        || sal_sum);
end;
/

--从调用者接收部门号，再从emp表查出该部门人数和工资总和
create or replace procedure count_emp2(
    deptno in emp.deptno%type
) as
    sal_sum   number;
    count_emp number;
begin
    select
        count(*),
        sum(sal) into sal_sum,
        count_emp
    from
        emp
    where
        deptno = deptno;
    dbms_output.put_line(deptno
        || '号部门人数为：'
        || count_emp);
    dbms_output.put_line(deptno
        || '号部门工资总和为：'
        || sal_sum);
end;
/

--从调用者接收部门号，再从emp表查出该部门人数和工资总和，并把这两个值通过out模式参数返回给调用者
create or replace procedure count_emp3(
    deptno in emp.deptno%type,
    count_emp out number,
    sal_sum out number
) as
begin
    select
        count(*),
        sum(sal) into sal_sum,
        count_emp
    from
        emp
    where
        deptno = deptno;
end;
/