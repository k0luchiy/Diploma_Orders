select 
	inv.InventoryId,
	invPr.ProductId, 
	(PrRe.Quantity - Sum(PrCon.Quantity) - InvPr.Quantity) as QuantityForOrder
from Inventory inv
	join InventoryProducts invPr on invPr.InventoryId=inv.InventoryId
	join ProductRequired PrRe on InvPr.ProductId=PrRe.ProductID
	join ProductConsumption PrCon on InvPr.ProductId=PrCon.ProductID
where 
	(inv.InventoryDate='InventoryDate') and 
	('DeliveryDate' between PrRe.FromDate and PrRe.ToDate) and
	(PrCon.FromDate between 'InventoryDate' and 'DeliveryDate')

group by 
	inv.InventoryId,
	invPr.ProductId
	
;