create index Index_Prod_Supp on ProductSupplier(ProductId, SupplierId);

create index Index_Product_Price on Products(ProductName, Price);
create index Index_Product_Category on Products(CategoryId);

create index Index_Required_Quantity on ProductRequired(ProductId, Quantity);
create index Index_Required_Dates on ProductRequired(FromDate, ToDate);

create index Index_Consumption_Quantity on ProductConsumption(ProductId, Quantity);
create index Index_Consumption_Dates on ProductConsumption(FromDate, ToDate);

create index Index_OrdersInfo on Orders(OrderId, OrderStatus, Cost);

create index Index_OrderProducts on OrderProducts(OrderId, ProductId);

create index Index_InventoryDate on Inventory(InventoryDate);
create index Index_IP on InventoryProducts(InventoryId, ProductId);