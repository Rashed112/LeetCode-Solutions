CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
SET N=N-1;
  RETURN (
      # Write your MySQL query statement below.
      Select distinct(salary) from Employee
      Order by salary desc
      LIMIT 1 OFFSET N  #Offset skips n rows and we can't do any calculation like n-1 here, so we had to set that out before
  );
END
