# Write your MySQL query statement below
SELECT e.NAME AS EMPLOYEE FROM EMPLOYEE as e
JOIN EMPLOYEE as s
ON e.MANAGERID=s.ID
WHERE e.salary>s.salary;
