package docs;

//  This class represents a shop where customers can enter, be served by servers, pay, and leave.
class Shop {
    // ... Your existing code ...

    /**
     * Customer enters the shop and acquires a spot in the waiting area.
     *
     * @param customer The customer entering the shop.
     */
    public void enterShop(Customer customer) {
        // ... Your existing code ...
    }

    // ... Other methods ...

    /**
     * Customer pays for their order and leaves the shop.
     *
     * @param customer The customer paying and leaving.
     */
    public void payAndLeave(Customer customer) {
        // ... Your existing code ...
    }
}

/**
 * This class represents a customer who enters the shop, places orders, and pays.
 */
class Customer extends Thread {
    // ... Your existing code ...

    @Override
    public void run() {
        // ... Your existing code ...
    }

    // ... Other methods ...

    /**
     * Returns a string representation of the customer.
     *
     * @return A string containing information about the customer.
     */
    @Override
    public String toString() {
        // ... Your existing code ...
        return ""; // Include a return statement here if needed.
    }
}

/**
 * This class represents a server who serves customers by making products.
 */
class Server extends Thread {
    // ... Your existing code ...

    /**
     * Returns a string representation of the server.
     *
     * @return A string containing information about the server.
     */
    @Override
    public String toString() {
        // ... Your existing code ...
        return ""; // Include a return statement here if needed.
    }
}
