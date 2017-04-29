# StoreManagement

3. PROPER TRENCH COATS

Trench coats are cool. Everyone should own a trench coat. The “Proper Trench Coats” store sells
fashionable, elegant trench coats and the store needs a software to allow their customers to “order
online”. The application can be used in two modes: administrator and user. When the application is
started, it will offer the option to choose the mode.

Administrator mode: The application will have a database, which holds all the available trench coats at
a given moment. The store employees must be able to update the database, meaning: add a new trench
coat, delete a trench coat (when it is sold out) and update the information of a trench coat. Each Trench
Coat has a size, a colour, a price, a quantity and a photograph. The photograph is memorised as a link
towards an online resource (the photograph on the presentation site of the store). The administrators
will also have the option to see all the trench coats in the store.

User mode: A user can access the application and choose one or more trench coats to buy. The
application will allow the user to:

a. See the trench coats in the database, having a given size, one by one. If the size is empty, then
all the trench coats will be considered. When the user chooses this option, the data of the first
trench coat (size, colour, price, quantity) is displayed, along with its photograph.


b. Choose to add the trench to the shopping basket. In this case, the price is added to the total sum
the user has to pay. The total sum will be shown after each purchase.


c. Choose not to add the trench coat to the basket and to continue to the next. In this case, the
information corresponding to the next trench coat is shown and the user is again offered the
possibility to buy it. This can continue as long as the user wants, as when arriving to the end of
the list, if the user chooses next, the application will again show the first trench coat.


d. See the shopping basket and the total price of the items.

EXTRA REQUIREMENTS:
1. Make sure you do not have any memory leaks in your program.
2. Add a new numeric data member to your entity class (e.g. for class Dog: weight, for class
Coat: length in cm, for class Movie: duration in minutes, for class Tutorial: number of
visualizations) and then overload the operator “<” for your entity: will return true if the
newly added data member is less than a given integer value. Then add a new option to
the administrator menu, which allows you to see all the entities in your list which have
the newly added data member less than a given value (input by the user). This filtering
must be done using the operator “<”.

