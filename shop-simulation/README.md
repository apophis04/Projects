# SHOP SIMULATION

**Project Description:**
The Shop Simulation project is a Java-based program designed to simulate the operations of a shop. It models a shop environment where customers can enter, place orders, be served by servers, pay for their orders, and leave the shop. The primary goal of this simulation is to illustrate concepts related to multi-threading and concurrent programming.

**Support My Work**

Hey there! 👋

I'm an independent creator working on various projects, from open-source software to content creation. If you find my work useful or enjoy what I do, consider supporting me with a virtual coffee!
Your support helps keep me fueled and motivated to continue creating and sharing. It's a small gesture that goes a long way in making a difference.

Thank you for being a part of my journey! ☕

--> [**Buy Me a Coffee ☕**](https://www.buymeacoffee.com/apophis04)


**Features:**
- Customers can enter the shop, place orders, and pay for their orders.
- Servers are available to serve customers by making products.
- Simulated customers and servers interact concurrently in a multi-threaded environment.

**How It Works:**
1. Customers enter the shop with a random order size between 1 and 25 products.
2. Servers are responsible for making the products for customers.
3. Servers can make a specific number of products at a time (e.g., Server 1 can make a maximum of 2 products at once).
4. Once a server has obtained all the items required for a customer's order, a final product is made, fulfilling part of the customer's order.
5. If a customer's entire order is not fulfilled during one server visit, the customer returns to the waiting area.
6. The waiting area is organized by the shortest order next.
7. Customers pay at a shared cash register and leave the shop.

**Project Structure:**
- ShopSimulation.java: The main class responsible for running the simulation.
- Shop.java: Represents the shop with methods to handle customer interactions.
- Customer.java: Represents a customer as a separate thread.
- Server.java: Represents a server as a separate thread.

**Getting Started:**
1. *Prerequisites:*
   - Java Development Kit (JDK) installed on your system.

2. *Installation:*
   - Clone the project repository from [repository_url].
   - Navigate to the project directory.

3. *Running the Simulation:*
   - Compile the code using the following command:
     ```
     javac -d . src/com/apophis/shop/*.java
     ```
   - *Run the simulation using the command:*
     ```
     java -cp src com.apophis.shop.ShopSimulation
     ```

**Contributing:**
- Contributions to this project are welcome via pull requests.

**License:**
- This project is open-source and is licensed under the MIT License. You can find the full license details in the LICENSE file.

**Additional Notes:**
- This simulation provides valuable insights into concurrent programming and can be a useful educational tool for understanding how multiple threads interact in a complex environment.
- Feel free to customize the simulation parameters in the ShopSimulation class to explore different scenarios.


