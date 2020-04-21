Singleton Pattern
The point of the Singleton pattern is that outside your class, only one instance of ChocolateBoiler can be obtained (via the getInstance method), since the private constructor can't be accessed from the outside.
Singleton Pattern is a convention for ensuring one and only one object is instantiated for a given class.
Has a private contructor. To get a hold of a Singleton object, you don’t instantiate one, you just ask
for an instance. So class has a static method called getInstance(). 
