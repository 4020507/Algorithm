SELECT FirstName, LastName, City, State FROM Person as P Left Join Address as A ON
P.PersonId = A.PersonId
