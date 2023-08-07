CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
SET N=N-1;
  RETURN (
      Select distinct(salary) from Employee
      Order by salary desc
      LIMIT 1 OFFSET N     #Offset skips n rows and we can't do any calculation like n-1 here, so we had to set that out before
  );
END
