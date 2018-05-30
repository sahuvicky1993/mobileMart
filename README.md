# mobileMart

A mobile shop wants you to develop an application to manage their inventory. The application should also allow some basic operations such as add, remove, search, etc. (More details at the bottom) 
Each mobile phone in the shop has the following attributes: 
• ID (unique number for the item) 
• Brand 
• Cost in Rs 
• Camera resolution (in mega pixels) 
• Inbuilt storage (in gigabytes) 

The shop only sells following types of mobile phones 
• Android (From various manufacturers) 
• iOS (From Apple only) 
• Windows Phone (From various manufacturers) 

Create the application with inventory containing the following data (you can put your own data):

The application should allow the following operations: 
1. Add : Add a mobile phone with the aforementioned attributes in the inventory 
2. Delete : Delete a mobile phone based on ID from the inventory 
1 3. Search : This is the most important operation. The user should be able to display all mobile phones based on brand, operating system, & cost. a. If no mobile phones match the search criteria, then a message should be displayed as following : 
2 

“No phones match the search criteria” 
4. Range-based Search – Display all phones within a specific range by cost. 

e.g. The user gives the following input range 
Minimum price : 10000 
Maximum price : 15000
This should display all phones that fall within this range, irrespective of the operating system. 
5. Display : Should show all the phones in the inventory 
6. ShowDiscountedPrice : This will show the discounted price of the phone. Android phones offer 2% discount, Windows phones 1% discount and Apple phones offer 0.5% discount ONLY if the price is above 25000. All Samsung phone have an additional 0.5% discount. 

Provide a facility to show the discounted price either by ID or brand (not OS).
