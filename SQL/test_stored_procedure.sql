USE Orders;  
GO 

IF OBJECT_ID('ProductConsumptionQuantity', 'P') IS NOT NULL  
   DROP PROCEDURE ProductConsumptionQuantity;  
GO  

CREATE PROCEDURE ProductConsumptionQuantity (
    @PrConDate date = GETDATE ,   
	@DeliveryDate date)
AS  
BEGIN
    SET NOCOUNT ON;  
	
	WHILE @PrConDate <= @DeliveryDate
	BEGIN
		Select ProductId, Quantity, @PrConDate as PrConDate
		from ProductConsumption PrCon
		where 
			@PrConDate between PrCon.FromDate and PrCon.ToDate and
			@PrConDate < @DeliveryDate;
		SET @PrConDate = DATEADD(day, 1, @PrConDate);
	END

	Return;
END
GO  