select A.Name as Employee from Employee as A where salary > 
(select B.Salary from Employee as B where A.ManagerId = B.id)
