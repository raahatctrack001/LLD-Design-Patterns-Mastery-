# Zomato LLD Interview - Requirement Gathering Notes

## Problem Statement

Design a simplified version of **Zomato** focusing on the core food ordering workflow. The objective is to produce a clean, extensible, object-oriented design rather than a production-scale distributed system.

---

# 1. Functional Requirements

The system should support the following capabilities:

## User Management

* Customer Registration
* Login / Logout
* Profile Management

### Roles

* Customer
* Restaurant Owner
* Delivery Partner
* Admin

---

## Restaurant Management

Restaurant owners should be able to

* Create Restaurant
* Update Restaurant Information
* Manage Menus
* Add Food Items
* Update Food Items
* Remove Food Items
* View Incoming Orders
* Accept / Reject Orders

---

## Menu & Food Management

* Create Menu
* Update Menu
* Delete Menu
* Add Food Items
* Modify Food Items
* Remove Food Items

---

## Cart Management

Customers should be able to

* Create Cart
* Add Items
* Remove Items
* Update Quantity
* View Cart
* Clear Cart

---

## Order Management

Customers

* Place Order
* View Active Order
* Cancel Order (before preparation)
* View Order History

Restaurant

* Accept Order
* Reject Order
* Update Preparation Status

Delivery Partner

* Pick Up Order
* Mark Order Delivered

---

## Search & Discovery

Search restaurants by

* Restaurant Name
* Food Item
* Cuisine
* Rating
* Nearby Restaurants

Sorting

* Rating
* Estimated Delivery Time

---

## Payment

Supported Payment Methods

* Credit / Debit Card
* UPI
* Cash on Delivery

Features

* Retry Payment
* Coupon Support
* Refund

---

## Communication

Notifications

* Push Notification
* SMS Notification

Messaging

* Customer ↔ Delivery Partner Chat

Additional

* Delivery Instructions

---

## Order Tracking

* Live Order Status
* Order History

---

## Reviews & Ratings

Customers can

* Give Star Rating
* Write Text Review

---

## Administration

Admin can

* Manage Users
* Manage Restaurants
* View Orders

---

## Authorization

Role Based Access Control

Roles

* Customer
* Restaurant Owner
* Delivery Partner
* Admin

---

# 2. Scope Definition

## Included

* User Management
* Restaurant Management
* Menu Management
* Food Item Management
* Cart Management
* Order Management
* Search & Filtering
* Payment Abstraction
* Order Tracking
* Reviews & Ratings
* Role-Based Authorization

---

## Excluded

* Recommendation Engine
* Advertisement System
* Loyalty & Rewards
* Analytics Dashboard
* Delivery Partner Assignment Algorithm
* Route Optimization
* Search Engine Internals
* Database Design
* Distributed Caching
* Microservices
* High-Level System Design

---

# 3. Assumptions

* Authentication is handled externally.
* One customer has one active cart.
* A cart belongs to only one restaurant.
* One order contains food from only one restaurant.
* One delivery partner handles one active order at a time.
* Delivery partner assignment is handled externally.
* GPS and Maps already exist.
* Payment Gateway already exists.

---

# 4. Non Functional Requirements

The design should be

* Modular
* Extensible
* Maintainable
* Testable
* Reusable
* Loosely Coupled
* Highly Cohesive
* SOLID Compliant
* Easy to Modify
* Easy to Unit Test

Focus is on clean object-oriented design rather than distributed system concerns.

---

# 5. Actors

Primary Actors

* Customer
* Restaurant Owner
* Delivery Partner
* Admin

External Actors

* Payment Gateway
* Notification Service
* Authentication Provider
* Maps Service
* Chat Service

---

# 6. Business Rules

* One customer can have only one active cart.
* A cart contains items from only one restaurant.
* One order belongs to one restaurant.
* Order cannot be modified after placement.
* Order can be cancelled only before preparation starts.
* Payment must succeed before restaurant starts preparing food.
* Restaurant may accept or reject an order.
* Customer can review an order only after successful delivery.
* One review is allowed per completed order.
* Restaurant can process multiple orders simultaneously.

---

# 7. Constraints

## Business Constraints

* Cart belongs to only one restaurant.
* One active cart per customer.

---

## Delivery Constraints

* One active delivery per delivery partner.
* Restaurant delivers only within configured delivery radius.

---

## Payment Constraints

* Payment required before preparation.
* Retry payment supported.
* Refund allowed only for cancelled orders.

---

## Review Constraints

* Review only after delivery.
* One review per order.

---

## Search Constraints

* Show only active/open restaurants.
* Show restaurants within serviceable area.

---

## Authorization Constraints

* Authentication handled externally.
* Authorization handled within application.

---

# 8. External Systems

The following are considered third-party services and will be represented using interfaces.

* Payment Gateway
* Authentication Service
* Notification Service
* Chat Service
* Maps / GPS Service

These services are outside the implementation scope.

---

# 9. Edge Cases

* Payment succeeds but order creation fails.
* Payment fails.
* Customer retries payment.
* Restaurant rejects order.
* Restaurant closes unexpectedly.
* Delivery partner unavailable.
* Customer cancels before preparation.
* Customer attempts cancellation after preparation starts.
* Duplicate payment request.
* Food item becomes unavailable after adding to cart.
* Customer attempts to review an undelivered order.

---

# 10. Future Extensibility

The design should allow easy addition of

* New Payment Methods
* Wallet Support
* New Notification Channels
* Loyalty Program
* Membership Plans
* Advertisement Module
* Recommendation Engine
* Multiple Delivery Strategies
* International Delivery
* New Search Algorithms
* New Discount Strategies
* Additional User Roles

The system should be open for extension without modifying existing business logic.

---

# 11. Requirement Freeze

### Summary

The system will model the complete food ordering workflow involving Customers, Restaurant Owners, Delivery Partners, and Admins.

The design includes

* User Management
* Restaurant Management
* Menu Management
* Cart
* Order Management
* Search
* Payment Abstraction
* Tracking
* Reviews
* Authorization

External services such as Payment Gateway, Authentication, Notifications, Chat, and Maps will be represented through interfaces.

The design will prioritize

* Maintainability
* Extensibility
* High Cohesion
* Low Coupling
* SOLID Principles
* Testability

Distributed system concerns, infrastructure, database implementation, analytics, recommendation systems, and route optimization are intentionally excluded from today's scope.

With the requirements finalized and the scope frozen, the design can now proceed to **Domain Modeling**, beginning with identifying the core domain entities and their relationships.


**Interviewer:**

Good. You're starting to identify entities instead of immediately drawing a UML. That's the correct direction.

However, if I were interviewing you, I would stop you here because you're **mixing three different concepts**:

1. **Domain Entities**
2. **Relationships**
3. **Service/Manager Classes**

These should be identified separately.

---

# Step 1 — Identify Domain Entities

First ask yourself:

> **"What are the nouns in the business domain?"**

From our requirements, I would expect something like:

## Core Entities

```text
User
Restaurant
Menu
FoodItem
Cart
CartItem
Order
OrderItem
Review
Address
```

### Supporting Entities

```text
Payment
Coupon
Notification
SearchCriteria (optional)
Delivery
```

Notice that I haven't included `UserManager` or `OrderManager` yet.

Those are **service classes**, not domain entities.

---

# Step 2 — Specialization

Instead of

```text
User
```

I'd ask:

Can User have different behaviors?

Yes.

Therefore,

```text
User
│
├── Customer
├── RestaurantOwner
├── DeliveryPartner
└── Admin
```

Inheritance (or Role composition, depending on the design) may emerge here.

---

# Step 3 — Now Relationships

This is where you describe associations.

For example:

```text
Customer
    1 ------ 1 Cart

Customer
    1 ------ * Orders

Restaurant
    1 ------ * Menus

Menu
    1 ------ * FoodItems

Cart
    1 ------ * CartItems

Order
    1 ------ * OrderItems

Restaurant
    1 ------ * Orders

DeliveryPartner
    1 ------ * CompletedOrders

Order
    1 ------ 1 Payment

Order
    1 ------ 0..1 Review

Restaurant
    1 ------ * Reviews
```

Notice how much richer the model becomes.

---

# What I don't agree with

You wrote:

> Cart has an active order and many non active order.

I would challenge that.

A **Cart** does **not own** orders.

Instead:

```text
Customer

↓

Cart

↓

Place Order

↓

Order
```

Once an order is placed,

the cart is cleared.

The order becomes an independent entity.

So I'd model it as

```text
Customer

1 -------- 1 Cart

Customer

1 -------- * Orders
```

not

```text
Cart

1 -------- * Orders
```

---

# Another issue

You wrote:

> Restaurant Manager has many restaurants

This sounds like a service.

Instead ask:

Is "Restaurant Manager" part of the business?

No.

It's an implementation detail.

Domain says

```text
RestaurantOwner

1 -------- * Restaurants
```

Much better.

---

Similarly

Instead of

```text
UserManager

has many Users
```

Domain says

```text
System

contains Users
```

or simply

```text
User Repository
```

Managers generally come much later if needed.

---

# A Better Entity List

If I were the candidate, I'd present:

```text
User
    ├── Customer
    ├── RestaurantOwner
    ├── DeliveryPartner
    └── Admin

Restaurant

Menu

FoodItem

Cart

CartItem

Order

OrderItem

Payment

Review

Coupon

Address
```

---

# Then Relationships

```text
Customer
    1 ---- 1 Cart

Customer
    1 ---- * Orders

RestaurantOwner
    1 ---- * Restaurants

Restaurant
    1 ---- * Menus

Menu
    1 ---- * FoodItems

Cart
    1 ---- * CartItems

Order
    1 ---- * OrderItems

Restaurant
    1 ---- * Orders

DeliveryPartner
    1 ---- * Orders

Order
    1 ---- 1 Payment

Order
    1 ---- 0..1 Review
```

---

# Interview Feedback

I would score this answer:

**7.5/10**

Not because the entities are wrong, but because you're jumping between **domain modeling** and **implementation classes**.

One important lesson:

> **During domain modeling, ignore Manager, Service, Controller, Repository, Factory, Singleton, Strategy, etc.**

Pretend you are a business analyst.

Ask:

> **"If I explain this system to a restaurant owner, what objects would they naturally mention?"**

Those are your domain entities.

Only after the domain model is stable should you introduce service classes, repositories, factories, design patterns, and other implementation details. That's how you keep the design clean and aligned with the business.





**Interviewer:**

Excellent.

We've now reached what I consider the **most important phase of an LLD interview**.

Most candidates think the next step is the UML.

I disagree.

There are still a few crucial steps before drawing the UML.

---

# Where we are

✅ Functional Requirements

✅ Scope

✅ Assumptions

✅ Non Functional Requirements

✅ Actors

✅ Business Rules

✅ Constraints

✅ External Services

✅ Edge Cases

✅ Future Extensibility

✅ Freeze Requirements

✅ Domain Entities

---

# Next Step

## Step 13 — Relationships

Not just associations.

You should identify the **type** of relationship.

For every relationship ask:

* Who owns whom?
* Can one exist without the other?
* What's the multiplicity?
* Is it inheritance?
* Is it composition?
* Is it aggregation?
* Is it dependency?
* Is it association?

Example:

```
Restaurant
      ♦──── Menu
```

Composition?

Aggregation?

Why?

You should be able to justify it.

---

After relationships,

---

# Step 14 — Responsibilities (CRC Analysis)

This is the phase almost everyone skips.

Ask

> **What is each class responsible for?**

Example

## Customer

Responsibilities

* Browse Restaurants
* Manage Cart
* Place Order
* Review Order

Collaborators

* Cart
* Order
* Restaurant

---

## Cart

Responsibilities

* Add Item
* Remove Item
* Calculate Total
* Validate Restaurant

Collaborators

* CartItem
* FoodItem

---

## Order

Responsibilities

* Maintain Order Status
* Calculate Amount
* Cancel Order
* Track Payment

Collaborators

* Payment
* Restaurant
* Delivery

---

Notice something?

Once responsibilities are clear,

methods almost write themselves.

---

# Step 15 — Interfaces & Abstractions

Now ask

Where can behavior vary?

For example

Payment

Today

```
UPI

Card

COD
```

Tomorrow

```
Wallet

Crypto
```

This suggests

```
PaymentStrategy
```

Similarly

Notification

```
SMS

Push

Email
```

suggests

```
NotificationService
```

---

# Step 16 — Identify Design Patterns

Now patterns emerge naturally.

For Zomato,

you may identify:

| Problem                         | Pattern                 |
| ------------------------------- | ----------------------- |
| Multiple payment methods        | Strategy                |
| Multiple notification channels  | Strategy                |
| Order lifecycle                 | State                   |
| Order creation                  | Builder (optional)      |
| Object creation                 | Factory                 |
| Restaurant observers (optional) | Observer                |
| Menu traversal (optional)       | Iterator                |
| Coupon validation (optional)    | Chain of Responsibility |

Notice we didn't force these patterns.

The problem led us to them.

---

# Step 17 — UML

Now draw the UML.

Why now?

Because you already know

* Entities
* Relationships
* Responsibilities
* Interfaces
* Patterns

The UML becomes much cleaner.

---

# Step 18 — Sequence Diagram

Now pick one use case.

Example

```
Place Order
```

Draw

Customer

↓

Cart

↓

OrderService

↓

PaymentGateway

↓

Restaurant

↓

Notification

↓

Delivery Assignment

↓

Order

---

This explains runtime interaction.

---

# Step 19 — Implementation

Now start coding.

---

# The Complete Flow

```
Requirement Gathering

↓

Freeze Scope

↓

Identify Entities

↓

Identify Relationships

↓

Assign Responsibilities

↓

Interfaces & Abstractions

↓

Design Patterns

↓

Class Diagram

↓

Sequence Diagram

↓

Implementation

↓

Review
```

---

# If I were your mentor...

I would actually slow you down **right here**.

I wouldn't let you touch UML yet.

Instead, I would spend **20–30 minutes** only on **Responsibilities**.

Why?

Because every beginner focuses on **"What classes do I need?"**

Experienced designers focus on:

> **"What responsibilities exist in the system?"**

This is the essence of the **GRASP (General Responsibility Assignment Software Patterns)** principles.

If responsibilities are assigned correctly:

* Methods become obvious.
* Design patterns emerge naturally.
* SOLID principles are easier to satisfy.
* The UML becomes simpler and more cohesive.

In my opinion, **responsibility assignment is the single most underrated skill in LLD interviews**, and it's what separates an average design from an excellent one.

So, as your interviewer, I'd ask you to proceed with **Step 13: identify and justify the relationships**, and then we'd move to **Step 14: responsibilities** before drawing any diagrams.
