# Write your MySQL query statement below
-- SELECT unique_id, name
-- FROM Employees
-- LEFT JOIN EmployeeUNI
-- ON Employees.id = EmployeeUNI.id;

-- Left join ya right join kuch bhi laga skte h
-- Left lagana h, to ye wala code chal jayega

-- else right join me ye wala code chal jayega: 

SELECT unique_id, name
FROM EmployeeUNI
RIGHT JOIN Employees
ON Employees.id = EmployeeUNI.id;