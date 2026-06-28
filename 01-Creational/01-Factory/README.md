# Factory Family Revision

The entire factory family exists to solve one fundamental architectural problem:

> “Object creation logic should not pollute business logic.”

Factories are primarily about:

* abstraction of instantiation
* reducing coupling
* controlling object lifecycle
* enabling scalability
* supporting extensibility without modification

Each one increases: simple, factory method, abstract factory

* abstraction
* flexibility
* scalability
* adherence to OCP/DIP

but also increases:

* indirection
* complexity
* number of classes

# Intent

A centralized class responsible for creating objects based on input parameters.

It encapsulates object creation logic in one place.

# Key Interview Vocabulary

* centralized object creation
* creation encapsulation
* conditional instantiation
* client decoupling
* construction abstraction
* static creation utility
* object provisioning layer

The Factory family exists to decouple object creation from object usage by centralizing instantiation logic, ensuring that business logic remains independent of concrete implementations and is not polluted by conditional object creation or construction details.

1. Simple Factory
Simple Factory exists to encapsulate conditional object creation into a single dedicated component, preventing clients from depending on concrete classes or scattering instantiation logic throughout the codebase.

Architecture focus:
Centralizes object creation.
Hides if-else/switch logic.
Reduces client coupling to concrete implementations.


2. Factory Method
Factory Method exists to eliminate direct dependencies on concrete implementations by delegating object creation to subclasses, allowing object creation behavior to vary without modifying the client or the framework.

Architecture focus:
Delegates creation responsibility.
Enables extensibility through inheritance.
Supports the Open/Closed Principle by allowing new products via new subclasses.

3. Abstract Factory
Abstract Factory exists to provide a unified interface for creating families of related or compatible objects, ensuring consistency between collaborating products while completely decoupling clients from their concrete implementations.

Architecture focus:
Creates entire product families.
Guarantees compatibility among created objects.
Enables switching entire ecosystems by replacing one factory implementation.