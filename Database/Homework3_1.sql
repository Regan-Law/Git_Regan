create or replace procedure countemp as
    sal_sum   number;
    emp_count number;
begin
    select
        count(*),
        sum(sal) into sal_sum,
        emp_count
    from
        emp
    where
        deptno = 30;
    dbms_output.put_line(emp_count
        ||' '
        ||sal_sum);
end;
/