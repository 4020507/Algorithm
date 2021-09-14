select a.Name as Customers from Customers as a left Join Orders as b on a.Id = b.CustomerId
where b.CustomerId is null
