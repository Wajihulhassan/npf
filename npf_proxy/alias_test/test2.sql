SELECT C.CustomerName, CONCAT(C.Address,', ',C.City,', ',C.PostalCode,', ',C.Country) AS Address FROM Customers AS C;
