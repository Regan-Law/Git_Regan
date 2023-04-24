--自然数50到100的和
declare
    n     number := 1;
    sum_n number := 0;
begin
    for n in 50 .. 100 loop
        sum_n:= sum_n+n;
    end loop;
    dbms_output.put_line('50到100的和为:'
        ||sum_n);
end;