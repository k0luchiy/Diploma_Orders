insert into Orders(CreatedDate, DeliveryDate) Values(GETDATE(), @DeliveryDate);

insert into OrderProducts(OrderId, ProductId, Qunatity) 
Values (@OrderId, @ProductId, @Quantity);

