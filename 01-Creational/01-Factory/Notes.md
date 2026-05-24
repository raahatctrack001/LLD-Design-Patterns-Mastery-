# Factory Family Revision

The entire factory family exists to solve one fundamental architectural problem:

> “Object creation logic should not pollute business logic.”

Factories are primarily about:

* abstraction of instantiation
* reducing coupling
* controlling object lifecycle
* enabling scalability
* supporting extensibility without modification

The progression usually goes:

```text
Simple Factory
    ↓
Factory Method
    ↓
Abstract Factory
```

Each one increases:

* abstraction
* flexibility
* scalability
* adherence to OCP/DIP

but also increases:

* indirection
* complexity
* number of classes

---

# 1. SIMPLE FACTORY

---

# Intent

A centralized class responsible for creating objects based on input parameters.

It encapsulates object creation logic in one place.

---

# Core Philosophy

> “Move object creation out of client code.”

Instead of:

```cpp
if(type == "car")
    vehicle = new Car();
else
    vehicle = new Bike();
```

the client delegates creation responsibility:

```cpp
vehicle = VehicleFactory.create(type);
```

---

# Why It Exists

Without factory:

```cpp
if(type == "paypal")
    payment = new PaypalProcessor();

if(type == "stripe")
    payment = new StripeProcessor();
```

Problems:

* repeated conditional logic
* tight coupling
* violates OCP
* difficult testing
* object creation scattered everywhere

Simple Factory centralizes this logic.

---

# UML Mental Model

```text
Client
   |
   v
SimpleFactory -----> ProductA
        \---------> ProductB
```

Factory knows all concrete implementations.

Client knows only:

* factory
* abstraction/interface

---

# Participants

## Product Interface

```cpp
class Vehicle {
public:
    virtual void drive() = 0;
};
```

Defines common contract.

---

## Concrete Products

```cpp
class Car : public Vehicle {};
class Bike : public Vehicle {};
```

Actual implementations.

---

## Factory

```cpp
class VehicleFactory {
public:
    static Vehicle* create(string type);
};
```

Creation orchestrator.

---

# Standard Implementation

```cpp
class Vehicle {
public:
    virtual void drive() = 0;
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    void drive() override {
        cout << "Driving Car\n";
    }
};

class Bike : public Vehicle {
public:
    void drive() override {
        cout << "Driving Bike\n";
    }
};

class VehicleFactory {
public:
    static Vehicle* createVehicle(string type) {

        if(type == "car")
            return new Car();

        if(type == "bike")
            return new Bike();

        return nullptr;
    }
};
```

---

# Runtime Flow

```text
Client → Factory.create()
              ↓
      instantiate concrete object
              ↓
      return abstraction pointer
```

---

# Key Interview Vocabulary

* centralized object creation
* creation encapsulation
* conditional instantiation
* client decoupling
* construction abstraction
* static creation utility
* object provisioning layer

---

# Advantages

## 1. Reduces Client Coupling

Client no longer depends on concrete classes.

---

## 2. Centralized Creation Logic

Easy to maintain.

---

## 3. Improves Readability

Business logic separated from construction logic.

---

## 4. Reusable Construction

Multiple clients use same creation mechanism.

---

# Drawbacks

## 1. Violates OCP

Adding new types requires modifying factory.

```cpp
if(type == "truck")
```

Factory becomes modification hotspot.

---

## 2. Factory Knows Everything

Creates God Object tendency.

---

## 3. High Conditional Complexity

Large switch/if ladders.

---

# SOLID Analysis

## Supports

### SRP

Client focuses on usage, factory on creation.

---

## Violates

### OCP

Must modify factory for new products.

---

### DIP (Partially)

Client still depends on factory implementation.

---

# Real World Examples

## Logger Factory

```cpp
LoggerFactory.create("file")
```

---

## Database Driver Selection

```cpp
DriverFactory.getDriver("mysql")
```

---

## Notification Provider

```cpp
NotificationFactory.create("email")
```

---

# When To Use

Use when:

* object creation is repetitive
* creation logic is simple
* small number of variants exist
* system unlikely to scale heavily

---

# When NOT To Use

Avoid if:

* product hierarchy frequently changes
* plugin architecture needed
* extensibility is critical

---

# Recognition Clues

If you see:

* repeated `new`
* repetitive switch-case
* creation scattered across codebase

→ Simple Factory may help.

---

# Interview Trap

Many candidates confuse Simple Factory with Factory Method.

IMPORTANT:

> Simple Factory is NOT an official GoF pattern.

It is more of a coding idiom.

---

# Mental Model

```text
“One shopkeeper creates all products.”
```

---

# Evolution Problem

As system grows:

```text
if(type == "car")
if(type == "bike")
if(type == "truck")
if(type == "bus")
if(type == "sports")
```

Factory becomes unstable.

This leads to:

# FACTORY METHOD

---

# 2. FACTORY METHOD

---

# Intent

Define an interface for object creation, but let subclasses decide which object to instantiate.

---

# Core Philosophy

> “Delegate creation responsibility to subclasses.”

Instead of one giant factory:

* every creator knows only its own product

---

# Fundamental Shift From Simple Factory

## Simple Factory

```text
ONE factory creates ALL products
```

## Factory Method

```text
Each subclass creates ITS OWN product
```

Huge architectural difference.

---

# UML Mental Model

```text
           Creator
              |
      factoryMethod()
              |
   -------------------
   |                 |
ConcreteCreatorA   ConcreteCreatorB
   |                 |
creates A          creates B
```

---

# Participants

## Product

```cpp
class Button
```

---

## Concrete Products

```cpp
WindowsButton
MacButton
```

---

## Creator Abstract Class

```cpp
class Dialog {
    virtual Button* createButton() = 0;
};
```

Contains factory method.

---

## Concrete Creators

```cpp
WindowsDialog
MacDialog
```

Override creation behavior.

---

# Standard Example

```cpp
class Button {
public:
    virtual void render() = 0;
};

class WindowsButton : public Button {
public:
    void render() override {
        cout << "Windows Button\n";
    }
};

class MacButton : public Button {
public:
    void render() override {
        cout << "Mac Button\n";
    }
};

class Dialog {
public:
    virtual Button* createButton() = 0;

    void renderWindow() {
        Button* btn = createButton();
        btn->render();
    }
};

class WindowsDialog : public Dialog {
public:
    Button* createButton() override {
        return new WindowsButton();
    }
};

class MacDialog : public Dialog {
public:
    Button* createButton() override {
        return new MacButton();
    }
};
```

---

# Key Architectural Insight

Factory Method uses:

* inheritance
* runtime polymorphism
* inversion of control

Creation responsibility moves downward.

---

# Runtime Flow

```text
Client → Creator reference
            ↓
    calls factoryMethod()
            ↓
subclass decides product
```

---

# Why It Is Powerful

Adding new product:

```cpp
class LinuxDialog : public Dialog
```

NO modification to existing creators.

OCP achieved.

---

# Interview Vocabulary

* polymorphic construction
* deferred instantiation
* subclass-driven creation
* extensible object provisioning
* inversion of creation control
* runtime product binding

---

# SOLID Principles

## Strong OCP Compliance

New products via extension.

---

## DIP

Client depends on abstractions.

---

## SRP

Creation separated cleanly.

---

# Advantages

## 1. Extensible

No central switch-case.

---

## 2. Scalable

Supports plugin-like systems.

---

## 3. Better Separation

Each creator owns one responsibility.

---

## 4. Runtime Flexibility

Dynamic creator substitution possible.

---

# Drawbacks

## 1. Class Explosion

Every product may need:

* product class
* creator class

---

## 2. Indirection

Harder debugging.

---

## 3. More Boilerplate

Too many subclasses.

---

# Real World Examples

## GUI Frameworks

OS-specific components.

---

## Logistics Systems

```text
RoadLogistics → Truck
SeaLogistics → Ship
```

---

## Spring Framework

Bean creation mechanisms.

---

# Recognition Clues

If requirements say:

* “framework decides subclass”
* “plugins”
* “extensible product hierarchy”
* “new types added frequently”

→ Factory Method.

---

# Mental Model

```text
“Each department manufactures its own product.”
```

---

# Evolution Problem

Factory Method handles ONE product family well.

But what if related products must be created together?

Example:

Windows UI needs:

* WindowsButton
* WindowsCheckbox
* WindowsScrollbar

Now consistency becomes important.

This leads to:

# ABSTRACT FACTORY

---

# 3. ABSTRACT FACTORY

---

# Intent

Provide an interface for creating families of related or dependent objects without specifying their concrete classes.

---

# Core Philosophy

> “Create entire compatible product families.”

---

# Most Important Interview Phrase

```text
Factory Method → creates ONE product

Abstract Factory → creates RELATED product families
```

---

# UML Mental Model

```text
GUIFactory
  | createButton()
  | createCheckbox()

      /          \
WindowsFactory   MacFactory
```

Each factory produces compatible ecosystem.

---

# Example Problem

Suppose:

```text
WindowsButton
WindowsCheckbox

MacButton
MacCheckbox
```

Mixing:

```text
WindowsButton + MacCheckbox
```

may break UI consistency.

Abstract Factory ensures compatibility.

---

# Participants

## Abstract Products

```cpp
Button
Checkbox
```

---

## Concrete Products

```cpp
WindowsButton
MacButton
WindowsCheckbox
MacCheckbox
```

---

## Abstract Factory

```cpp
GUIFactory
```

---

## Concrete Factories

```cpp
WindowsFactory
MacFactory
```

---

# Standard Example

```cpp
class Button {
public:
    virtual void paint() = 0;
};

class Checkbox {
public:
    virtual void check() = 0;
};

class WindowsButton : public Button {
public:
    void paint() override {
        cout << "Windows Button\n";
    }
};

class WindowsCheckbox : public Checkbox {
public:
    void check() override {
        cout << "Windows Checkbox\n";
    }
};

class GUIFactory {
public:
    virtual Button* createButton() = 0;
    virtual Checkbox* createCheckbox() = 0;
};

class WindowsFactory : public GUIFactory {
public:
    Button* createButton() override {
        return new WindowsButton();
    }

    Checkbox* createCheckbox() override {
        return new WindowsCheckbox();
    }
};
```

---

# Runtime Flow

```text
Client → Factory
           ↓
 creates consistent product ecosystem
```

---

# Key Insight

Abstract Factory is:

* factory of factories
* family provider
* consistency enforcer

---

# Interview Vocabulary

* product family encapsulation
* cross-product compatibility
* ecosystem consistency
* related object provisioning
* family-level abstraction
* coordinated object creation

---

# SOLID Analysis

## Excellent OCP

Add new families easily.

---

## Strong DIP

Entire system abstraction-driven.

---

## High Cohesion

Related products grouped together.

---

# Advantages

## 1. Guarantees Compatibility

Huge enterprise advantage.

---

## 2. Easy Product Family Swap

```cpp
factory = new MacFactory();
```

Entire UI changes.

---

## 3. Centralized Family Creation

Strong consistency.

---

## 4. Plugin Architecture Friendly

Very scalable.

---

# Drawbacks

## 1. Difficult To Add New Product Types

Adding:

```text
Slider
```

requires:

* abstract factory update
* all concrete factories update

Major drawback.

---

## 2. High Complexity

Many interfaces/classes.

---

## 3. Heavy Architecture

Can become overengineering.

---

# Real World Examples

## Cross Platform UI Frameworks

Qt, Java Swing look-and-feel.

---

## Database Drivers

```text
OracleConnection
OracleCommand

MySQLConnection
MySQLCommand
```

---

## Cloud SDKs

AWS/GCP/Azure service families.

---

# Pattern Relationships

## Abstract Factory Uses Factory Method Internally

Very common interview question.

Each method:

```cpp
createButton()
```

is itself a Factory Method.

---

# Comparison Summary

| Feature             | Simple Factory | Factory Method | Abstract Factory   |
| ------------------- | -------------- | -------------- | ------------------ |
| GoF Pattern         | No             | Yes            | Yes                |
| Uses Inheritance    | No             | Yes            | Sometimes          |
| Creates             | Any objects    | One product    | Product families   |
| OCP                 | Weak           | Strong         | Strong             |
| Complexity          | Low            | Medium         | High               |
| Scalability         | Limited        | Good           | Excellent          |
| Centralized Factory | Yes            | No             | Multiple factories |

---

# Ultra Important Interview Insight

## Factory Method focuses on:

```text
WHICH concrete object gets created
```

## Abstract Factory focuses on:

```text
WHICH FAMILY of objects gets created
```

---

# Quick Recognition Cheat Sheet

## Simple Factory

Keywords:

* centralized creation
* switch-case removal

---

## Factory Method

Keywords:

* subclass decides creation
* extensibility
* framework design

---

## Abstract Factory

Keywords:

* product families
* compatibility
* themes/platforms/ecosystems

---

# Senior-Level Architectural Insight

Factories are foundational to:

* Dependency Injection containers
* Spring Beans
* Hibernate SessionFactory
* React component abstraction
* Plugin systems
* Cloud SDKs
* Driver architectures
* Service registries

Almost every large-scale framework internally uses factory-based object provisioning.
