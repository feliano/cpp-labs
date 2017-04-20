## Lab 8 - Bool Matrix

####Describe what a template specialization is
It's a way of adding specific behaviour for a class with a certain type. a specialization overrides the generic template implementation and allows 
it to the differ from how other types are treated.

####This is specialization of the Matris class. What other specialization than a class template specialization is possible?
This is a full class specialization but it's also possible to do a partial specialization where some parts of the templates are specialized.

I did function tmeplate specialization  for the identity() function. 


####How does your proxy class work?
proxyn tar en referens till en uint64 och ett bit-index som parametrar och sparar dessa som members.
Proxyn overloadar operator= (bool b) och som tilldelar bool-värdet b till den bit som proxyns members pekar på.

proxyn overloadar även operator bool() som möjliggör att proxyn kan jämföras med andra bool-värden.

####What is the meaning of the word proxy?
ombud, person eller en enhet med tillåtelse att agera åt någon. 

####How much does this code differ form your solution of lab 5?
Alla index-beräkningar är nog de största skillnaderna och det gör att alla metoder skiljer sig från lab5 även om tankesättet är likt

####What was most difficult to implement?
Addition/removal of columns & proxy. 
