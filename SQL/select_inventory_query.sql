 Select pr.ProductId, pr.ProductName, pc.CategoryName, pr.CaseQuantity, pr.Units  
 from Products pr
 join ProductCategory pc on pr.CategoryId=pc.CategoryId;