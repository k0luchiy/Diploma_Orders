select Pr.ProductId, Pr.ProductName, Sup.SupplierName, Pr.CaseQuantity, Pr.Units, Pr.Price
from Products Pr
join ProductSupplier PrSup on Pr.ProductId=PrSup.ProductId
join supplier Sup on PrSup.SupplierId=Sup.SupplierId;