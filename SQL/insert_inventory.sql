insert into Inventory(InventoryDate)
Values (GETDATE());


insert into InventoryProducts(InventoryId, ProductId, Quantity)
Values(@InventoryId, @ProductId, @Quantity);