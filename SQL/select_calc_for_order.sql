DECLARE @InventoryId int = 5
DECLARE @DeliveryDate date = '2023-11-05'
--DECLARE @PrConDate date = GETDATE()

;with GetDateRange(AllDates) as (
	select GETDATE() as allDates
	union all
	select dateadd(day, 1, alldates) from GetDateRange
	where alldates <= @DeliveryDate
),

ProductConsumptionRange(ProductId, Quantity) as (
	Select ProductId, Sum(Quantity)
	from ProductConsumption PrCon, GetDateRange
	where 
		AllDates between PrCon.FromDate and PrCon.ToDate 
		--and AllDates < @DeliveryDate
	group by ProductId
)

select 
	Pr.ProductId, Pr.ProductName, Sup.SupplierName, 
	Pr.CaseQuantity, Pr.Units, Pr.Price, 
	(PrReq.Quantity - PrCon.Quantity - InvPr.Quantity) as Quantity
from Products Pr
join ProductRequired PrReq on Pr.ProductId=PrReq.ProductID
join ProductConsumptionRange PrCon on Pr.ProductId=PrCon.ProductID
join InventoryProducts InvPr on Pr.ProductId=InvPr.ProductId
join ProductSupplier PrSup on PrSup.ProductId=Pr.ProductId
join supplier Sup on Sup.SupplierId=PrSup.SupplierId
Where 
	@InventoryId = InvPr.InventoryId and
	@DeliveryDate between PrReq.FromDate and PrReq.ToDate 
	--@DeliveryDate between PrCon.FromDate and PrCon.ToDate





/*
with ProductConsumptionRange(ProductId, Quantity) as (
	Select ProductId, Quantity
	from ProductConsumption PrCon
	where 
		@PrConDate between PrCon.FromDate and PrCon.ToDate and
		@PrConDate < @DeliveryDate

)


select 
	Pr.ProductId, Pr.ProductName, Sup.SupplierName, 
	Pr.CaseQuantity, Pr.Units, Pr.Price, 
	(PrReq.Quantity - PrCon.Quantity - InvPr.Quantity) as Quantity
from Products Pr
join ProductRequired PrReq on Pr.ProductId=PrReq.ProductID
join ProductConsumption PrCon on Pr.ProductId=PrCon.ProductID
join InventoryProducts InvPr on Pr.ProductId=InvPr.ProductId
join ProductSupplier PrSup on PrSup.ProductId=Pr.ProductId
join supplier Sup on Sup.SupplierId=PrSup.SupplierId
Where 
	@InventoryId = InvPr.InventoryId and
	@DeliveryDate between PrReq.FromDate and PrReq.ToDate and 
	@DeliveryDate between PrCon.FromDate and PrCon.ToDate
*/
