# The Complete LLD Requirement Gathering Framework

Whenever an interviewer says:

> "Design X."

your brain should automatically follow this sequence.

```
1. Functional Requirements
2. Non-Functional Requirements
3. Scope Definition
4. Assumptions (clearly state the assumptions)
5. Constraints
6. Actors
7. External Systems
8. Business Rules
9. Edge Cases
10. Future Extensibility
```

---

# 1. Functional Requirements (WHAT should the system do?)

These are the actual features.

Ask yourself:

## User Management

* Register?
* Login?
* Logout?
* OAuth?
* Guest user?
* Profile management?

---



## Search

* Search by 
    * Name
    * Category
    * Date
    * Location
    * Tags
    * Price
* Filter
* Sort

---

## CRUD

What can users create?

* Create
* Read
* Update
* Delete

---

## Transactions

Can users

* Buy
* Sell
* Book
* Order
* Cancel
* Refund
* Return
* Exchange

---

## Communication

Need

Communication
    ├── Notification
    │      ├── Email
    │      ├── SMS
    │      ├── Push
    │      ├── In-App Notification
    │      └── Web Notification
    │
    ├── Messaging
    │      ├── One-to-One Chat
    │      ├── Group Chat
    │      ├── Attachments
    │      └── Message History
    │
    ├── Voice
    │      ├── Audio Call
    │      └── Voicemail
    │
    ├── Video
    │      ├── Video Call
    │      └── Conference
    │
    ├── Live Events
    │      ├── Streaming
    │      └── Broadcasting
    │
    └── Collaboration
           ├── Comments
           ├── Mentions
           ├── Replies
           └── Presence (Online/Offline)

---

## Payments

Need

* Multiple payment methods? phonepay googleplay bharatpay amazonpay whatsapp
* Wallet?
* Coupons?
* Partial payment?
* Retry payment?
* GiftCard?

Payment

├── Payment Method
│      Card
│      UPI
│      Wallet
│      Net Banking
│
├── Discounts
│      Coupon
│      Promo
│      Loyalty
│
├── Billing
│      Invoice
│      Tax
│
├── Refund
│
└── Transaction History
---

## Tracking

Need

* Live status?
* History?
* Logs?
* Analytics?

---

## Reviews

Need

* Rating?
* Reviews?
* Like?
* Report?
* Comments?

---

## Administration

Admin can

* Manage users
* Delete data
* Approve content
* Manage reports
* View analytics
* Block users

---

## Permissions

Different roles?

Example

```
Customer

Restaurant

Delivery Partner

Admin
```

---

# 2. Non-Functional Requirements (HOW should it behave?)
Since this is an LLD interview, I'll focus on maintainability, extensibility, and clean object-oriented design. Unless there are specific performance constraints that affect the object model, I'll avoid making distributed system assumptions.


These are NOT features.

These define system quality.

---

## Performance

Questions

* Expected response time?
* Maximum latency?

---

## Scalability

Need to support

* 100 users?
* 10 million users?

---

## Availability

Should system always work?

99%

99.9%

99.99%

---

## Reliability

Can data be lost?

---

## Consistency

Strong consistency?

Eventual consistency?

---


## Security

Authentication
Authorization
Encryption
Secure payments

---

## Maintainability

Easy to modify?

---

## Extensibility

Can new features be added easily?

---

## Fault Tolerance

What happens if payment fails?

---

## Auditability

Need logs?

---

## Monitoring

Need metrics?

---

## Portability

Web only?

Mobile?

Desktop?

---

# 3. Scope Definition

Since Zomato is a very large system and an LLD interview has limited time, I'd like to freeze the scope before proceeding further.

Based on the functional requirements we've discussed, I'd propose that today's design focuses on the core food ordering workflow.

### Included in Scope

* User Management (Customer, Restaurant Owner, Delivery Partner, Admin)
* Restaurant Management
* Menu & Food Item Management
* Cart Management
* Order Management
* Restaurant Search and Filtering
* Order Lifecycle & Tracking
* Reviews and Ratings
* Role-based Permissions

### External Systems (Assumed)

To keep the focus on object-oriented design rather than third-party integrations, I'd treat the following as external services accessed through interfaces:

* Payment Gateway
* Notification Service (SMS, Push Notifications)
* Chat Service
* Authentication Provider (if authentication details are not the focus)
* Maps/GPS Service

### Out of Scope

For today's discussion, I'd exclude:

* Recommendation Engine
* Advertisement System
* Loyalty & Rewards
* Analytics & Reporting
* Delivery Partner Assignment Algorithm
* Route Optimization
* Search Engine Internals
* Database Design
* Caching
* Distributed System Concerns
* Microservices Architecture

Does this scope align with what you expect for today's interview?


Very important.
Interviewers intentionally ask huge systems.
You should reduce scope.
    included: list
    excluded: list

Example

Instead of

> Design Zomato

Clarify

"We'll only cover food ordering, not restaurant onboarding, delivery optimization, recommendations, advertising, or payment gateway internals."

This is appreciated.

---

# 4. Assumptions

If interviewer doesn't answer,

state assumptions.

Example

```
One restaurant fulfills one order.
One delivery partner handles one order.
Payment gateway already exists.
GPS service already exists.
```

---

# 5. Constraints

Identify limitations.

Example

```
Maximum order size
Maximum seats
Maximum passengers
Maximum bookings
Delivery radius
Maximum concurrent users
```

---

# 6. Actors

Who uses the system?

Example

```
Customer
Restaurant
Delivery Partner
Admin
```

Sometimes also

```
Guest
Support
Manager
Warehouse
Payment Gateway
```

---

# 7. External Systems

Very commonly forgotten.

Examples

```
Payment Gateway
Google Maps
Email Service
SMS Service
Push Notifications
Inventory System
Authentication Provider
Cloud Storage
Tax Service
Third party APIs
```

Don't design them.

Treat them as interfaces.

---

To summarize, we'll design the core food-ordering workflow involving four actors: Customer, Restaurant Owner, Delivery Partner, and Admin. The system includes user, restaurant, menu, cart, order, search, tracking, reviews, and role management. We'll keep the design modular, extensible, loosely coupled, and testable. Payment, notifications, authentication, chat, and maps will be treated as external services through interfaces. We'll exclude distributed system concerns, recommendations, analytics, route optimization, and delivery assignment. Unless you have any additional requirements, I'd like to freeze the scope and move on to identifying the domain entities and their relationships.


# 8. Business Rules

Interviewers LOVE this.

Example

```
Order cannot be cancelled after pickup.
Coupon usable once.
Restaurant can reject order.
Delivery partner cannot take multiple orders.
Rating allowed only after delivery.
```

---

# 9. Edge Cases

Think like QA.

Example

```
Restaurant closes suddenly
Delivery partner unavailable
Payment succeeds but order fails
Duplicate payment
Customer loses internet
Food unavailable
Coupon expired
Restaurant removed
```

---

# 10. Future Extensibility

Mention future possibilities.

Example

```
Multiple payment providers
New notification channels
International delivery
Subscriptions
AI recommendations
Loyalty points
```

Interviewers LOVE hearing

> "I'll keep the design open for future extension."

---

# Requirement Gathering Checklist (Memorize This)

```
Functional Requirements: 

User Management
Authentication
Search
CRUD
Booking / Ordering
Payment
Tracking
Notification
Review
Admin Features
Reports
Permissions
```

---

```
Non Functional:

Performance
Scalability
Availability
Reliability
Security
Maintainability
Extensibility
Monitoring
Logging
Consistency
```

---

```
Project Scope

Included Features
Excluded Features
Assumptions
Constraints
Business Rules
Actors
External Services
Edge Cases
Future Enhancements
```

---

# Example: Zomato Clone

Here's how a strong candidate might summarize the requirements after discussion.

### Functional Requirements

* User registration and authentication
* Browse restaurants
* Search and filter restaurants
* View restaurant details and menu
* Add/remove items from cart
* Place an order
* Apply coupons
* Make payments through supported payment providers
* Track order status
* Cancel an order before preparation starts (or according to business rules)
* View order history
* Rate and review restaurants and completed orders
* Restaurant can manage menu and accept/reject orders
* Delivery partner can accept assigned deliveries and update delivery status
* Admin can manage users, restaurants, and reports

### Non-Functional Requirements

* Modular and extensible design
* High cohesion and low coupling
* Easy addition of new payment providers
* Easy addition of new notification channels
* Thread-safe handling of shared resources if needed
* Good maintainability and testability
* Clear separation of concerns

### Scope (for this interview)

Included:

* Food ordering workflow
* Restaurant management
* Cart
* Order lifecycle
* Payment abstraction
* Notifications

Excluded:

* Recommendation engine
* Search indexing
* Delivery route optimization
* Load balancing
* Database sharding
* Distributed caching
* Microservices
* Analytics

### Actors

* Customer
* Restaurant
* Delivery Partner
* Admin

### External Systems

* Payment Gateway
* Maps/GPS
* Notification Service (Email/SMS/Push)

### Business Rules

* A customer can have only one active cart per restaurant.
* An order cannot mix items from multiple restaurants.
* Payment must succeed before the restaurant begins preparation.
* Reviews are allowed only for delivered orders.

### Assumptions

* Restaurant inventory is always up to date.
* Delivery partner assignment is handled by another service.
* Authentication is already implemented.
* Taxes are calculated by an external service.

### Constraints

* One delivery partner serves one order at a time.
* Delivery is limited to restaurants within the serviceable area.
* Coupon validation is delegated to a coupon service.

---

## What interviewers expect

One thing to keep in mind is that **LLD and HLD interviews have different expectations**:

* In **LLD**, interviewers expect you to ask just enough questions to define the object model and business rules. You don't need to dive deeply into scalability, distributed systems, or infrastructure unless they materially affect your class design.
* In **HLD**, questions about throughput, availability, caching, databases, load balancing, and distributed architecture become much more important.

A strong LLD candidate gathers requirements efficiently, freezes the scope, and then moves confidently into identifying entities and designing classes.




I actually think this is worth making into something much bigger.

What you're asking for is not a checklist—it's an **architectural ontology** (a taxonomy of software capabilities). This is how architects mentally decompose systems before they ever think about classes or design patterns.

If I were mentoring someone for FAANG/MAANG SDE-2 interviews, this is the framework I'd teach.

---

# Universal Software Capability Taxonomy (USCT)

This is **not** specific to LLD.

This is applicable to

* LLD
* HLD
* System Design
* Product Design
* Requirement Gathering
* Software Architecture

Almost every software system can be decomposed into these domains.

```
Software System
│
├── 1. Identity & Access
├── 2. User Management
├── 3. Core Business Domain
├── 4. Transactions
├── 5. Discovery
├── 6. Communication
├── 7. Content Management
├── 8. Collaboration
├── 9. Payment & Billing
├── 10. Workflow & Lifecycle
├── 11. Administration
├── 12. Analytics & Reporting
├── 13. Integrations
├── 14. Security
├── 15. Quality Attributes
├── 16. Constraints
├── 17. Future Extensibility
```

Notice something.

These are **domains**, not features.

---

# 1. Identity & Access

Ask:

How do users prove who they are?

```
Identity

├── Registration
├── Login
├── Logout
├── Forgot Password
├── Email Verification
├── OTP
├── MFA
├── OAuth
├── Session
├── JWT
└── API Keys
```

Then

```
Access

├── Roles
├── Permissions
├── Authorization
├── Resource Ownership
└── Access Policies
```

---

# 2. User Management

```
User

├── Profile
├── Preferences
├── Address
├── Contacts
├── Avatar
├── Settings
├── Devices
├── Activity
└── Account Deletion
```

---

# 3. Core Business Domain

This changes with every project.

For Uber

```
Ride

Driver

Vehicle
```

For Amazon

```
Product

Inventory

Seller
```

For Zomato

```
Restaurant

Menu

Food Item

Order
```

This is the heart of the application.

---

# 4. Transactions

Ask

Can something happen?

```
Transaction

├── Create
├── Modify
├── Cancel
├── Retry
├── Refund
├── Return
├── History
└── Status
```

Examples

Order

Booking

Ride

Reservation

Purchase

Enrollment

Appointment

---

# 5. Discovery

How does user find things?

```
Discovery

├── Search
├── Filter
├── Sort
├── Pagination
├── Recommendation
├── Trending
├── Categories
├── Suggestions
└── Nearby
```

---

# 6. Communication

Now your earlier observation fits naturally.

```
Communication

├── Notifications
│     ├── Push
│     ├── Email
│     ├── SMS
│     ├── In-App
│     └── Web
│
├── Messaging
│     ├── Direct Chat
│     ├── Group Chat
│     ├── Attachments
│     └── Message History
│
├── Voice
│     ├── Call
│     └── Voicemail
│
├── Video
│     ├── Call
│     └── Conference
│
├── Presence
│     ├── Online
│     ├── Typing
│     ├── Read Receipt
│     └── Last Seen
│
└── Media Sharing
      ├── Images
      ├── Videos
      ├── Documents
      └── Location
```

Much cleaner.

---

# 7. Content Management

```
Content

├── Create
├── Read
├── Update
├── Delete
├── Upload
├── Download
├── Archive
├── Versioning
└── Moderation
```

Applicable to

Blogs

Videos

Courses

Documents

Posts

---

# 8. Collaboration

```
Collaboration

├── Comments
├── Replies
├── Mentions
├── Reactions
├── Sharing
├── Following
├── Invitations
├── Teams
└── Permissions
```

---

# 9. Payment & Billing

```
Payment

├── Payment Methods
│      Card
│      UPI
│      Wallet
│      Net Banking
│
├── Discounts
│      Coupon
│      Promo
│      Loyalty
│
├── Billing
│      Invoice
│      Tax
│
├── Refund
│
├── Subscription
│
└── Transaction History
```

---

# 10. Workflow & Lifecycle

Every system has states.

```
Lifecycle

Created

Pending

Accepted

Processing

Completed

Cancelled

Failed

Archived
```

Ask

How does the object move between states?

This is where State Pattern often appears.

---

# 11. Administration

```
Admin

├── User Management
├── Role Management
├── Content Moderation
├── Reports
├── Dashboard
├── Configuration
├── Audit
└── System Settings
```

---

# 12. Analytics & Reporting

```
Analytics

├── Dashboard
├── Statistics
├── Reports
├── Trends
├── Revenue
├── User Activity
├── Logs
└── Export
```

---

# 13. Integrations

```
External Systems

├── Payment Gateway
├── Maps
├── GPS
├── SMS
├── Email
├── Storage
├── Authentication
├── AI Service
├── Tax Service
├── Recommendation Engine
└── Third-party APIs
```

Don't design them.

Just abstract them.

---

# 14. Security

```
Security

├── Authentication
├── Authorization
├── Encryption
├── Validation
├── Rate Limiting
├── Audit Logs
├── Privacy
└── Compliance
```

---

# 15. Quality Attributes

These are your Non-Functional Requirements.

```
Quality

├── Extensibility
├── Maintainability
├── Scalability
├── Reliability
├── Availability
├── Performance
├── Testability
├── Reusability
├── Modularity
└── Fault Tolerance
```

These directly influence your class design.

---

# 16. Constraints

```
Constraints

├── Capacity
├── Quantity
├── Size
├── Time
├── Distance
├── Frequency
├── Cost
└── Legal
```

Examples

```
Maximum cart size

Maximum booking seats

Delivery radius

Coupon usage

Maximum upload size
```

---

# 17. Future Extensibility

Always ask

What could change?

```
Future

├── New Payment Provider
├── New Notification Channel
├── New User Role
├── New Discount Type
├── New Search Algorithm
├── New Delivery Strategy
├── Internationalization
└── Plugin Support
```

This is where design patterns often emerge naturally.

---

# The Interview Flow

Now let's turn the taxonomy into a practical interview flow.

When the interviewer says:

> "Design X"

Your mental algorithm should be:

```
Step 1
Understand the product.

↓

Step 2
Identify actors.

↓

Step 3
Identify Core Business Domain.

↓

Step 4
Walk through every domain.

Identity

↓

User

↓

Business

↓

Transactions

↓

Discovery

↓

Communication

↓

Payment

↓

Workflow

↓

Administration

↓

Integrations

↓

Security

↓

Quality

↓

Constraints

↓

Future

↓

Freeze requirements.
```

If a domain is irrelevant, simply skip it.

---

# Example: Parking Lot

Communication?

Skip.

Payments?

Optional.

Messaging?

Skip.

Analytics?

Skip.

Workflow?

Yes.

Core Business?

Vehicle

Parking Spot

Ticket

---

# Example: WhatsApp

Communication?

Huge.

Payments?

Optional.

Discovery?

Minimal.

Workflow?

Minimal.

---

# Example: Amazon

Discovery?

Huge.

Payments?

Huge.

Communication?

Medium.

Workflow?

Huge.

---

# Why this framework is powerful

Most candidates think in terms of **features**:

> "Does it need coupons?"

> "Does it need chat?"

Experienced engineers think in terms of **capabilities**:

> "Does this system require communication?"

> "Does it require transactional workflows?"

> "Does it require discovery?"

Only after identifying a capability do they drill down into specific features.

That shift—from feature-oriented thinking to capability-oriented thinking—is what makes requirement gathering systematic instead of relying on memory.

---




***************************************************************************
***************************************************************************
***************************************************************************
***************************************************************************
***************************************************************************
***************************************************************************
***************************************************************************

# LLD Interview Notes - Requirement Gathering & Design Framework

---

# 1. Goal of Requirement Gathering

The objective is **not** to collect every possible feature.

The objective is to remove ambiguity so that the object model becomes clear.

Never jump directly into classes or code.

First understand **what** needs to be built.

---

# 2. Mindset During an Interview

The interviewer is **not** going to tell you everything.

The interviewer provides a vague problem statement.

It is my responsibility to ask the right questions and gather the required information.

Think like a Software Engineer discussing requirements with a client.

---

# 3. Universal LLD Interview Framework

## Requirement Gathering

### Step 1 — Functional Requirements

Understand what the system should do.

Think in terms of capabilities instead of individual features.

Possible capability domains:

* Identity & Access
* User Management
* Core Business Domain
* Transactions
* Discovery
* Communication
* Content Management
* Collaboration
* Payment & Billing
* Workflow & Lifecycle
* Administration
* Analytics & Reporting

---

### Step 2 — Scope Definition

Freeze the interview scope.

Included Features

Excluded Features

Never try to design the entire production system.

---

### Step 3 — Assumptions

If the interviewer says

"You decide"

state assumptions explicitly.

Never assume silently.

Examples:

* One active cart per customer.
* One restaurant per order.
* Authentication handled externally.
* Delivery assignment handled externally.

---

### Step 4 — Non Functional Requirements

For LLD focus on:

* Modularity
* Extensibility
* Maintainability
* High Cohesion
* Low Coupling
* Testability
* Reusability
* Clear Separation of Concerns
* SOLID Principles

Avoid discussing:

* Load Balancer
* Caching
* Database Sharding
* Distributed Systems

unless specifically asked.

---

### Step 5 — Actors

Identify every actor.

Examples

Customer

Restaurant Owner

Delivery Partner

Admin

Actors define who interacts with the system.

---

### Step 6 — Business Rules

Business Rules define the application's behavior.

Examples

* Cart belongs to one restaurant.
* Order cannot be modified after placement.
* Reviews allowed only after delivery.
* Payment required before preparation.

Business Rules influence object behavior.

---

### Step 7 — Constraints

Constraints define limits.

Examples

* Delivery Radius
* One active delivery per rider
* Retry payment three times
* Maximum cart size

Business Rule != Constraint

Business Rule

Order cannot be modified.

Constraint

Maximum delivery distance is 15 km.

---

### Step 8 — External Systems

Treat external services as interfaces.

Examples

* Payment Gateway
* Notification Service
* Authentication Provider
* Maps
* Chat Service

Never design these systems unless asked.

---

### Step 9 — Edge Cases

Always think about failure scenarios.

Examples

* Payment succeeds but order creation fails.
* Restaurant rejects order.
* Rider unavailable.
* Customer cancels during preparation.
* Duplicate payment.
* Restaurant closes unexpectedly.

---

### Step 10 — Future Extensibility

Ask yourself

"What is likely to change?"

Examples

* New payment methods
* New notification channels
* Loyalty program
* International delivery
* New discount strategies

Good designs anticipate change.

---

### Step 11 — Freeze Requirements

Summarize everything.

Only after interviewer agrees,

begin the design.

---

# 4. Design Phase

After freezing requirements

follow this order.

---

## Step 12

Identify Domain Entities

---

## Step 13

Identify Relationships

Association

Aggregation

Composition

Inheritance

Dependency

---

## Step 14

Assign Responsibilities

Every class should have one clear responsibility.

Don't think

"What data does it store?"

Think

"What is it responsible for?"

---

## Step 15

Design Interfaces & Abstractions

Create interfaces where behavior varies.

Abstractions should appear before design patterns.

---

## Step 16

Identify Design Patterns

Patterns should emerge naturally.

Never force a design pattern.

---

## Step 17

Draw Class Diagram

Show

* Classes
* Interfaces
* Relationships
* Multiplicity
* Visibility

---

## Step 18

Draw Sequence Diagram

Show runtime interaction.

Which object calls whom?

In what order?

---

## Step 19

Implementation

Implement incrementally.

Keep SOLID in mind.

---

## Step 20

Refactoring

Review

Can this design be improved?

Can duplication be removed?

Can new features be added without modification?

---

## Step 21

Trade-offs

Always be prepared to discuss

Why this design?

Why not another approach?

What assumptions were made?

What limitations remain?

---

# 5. Important Interview Learnings

Requirement gathering is collaborative.

Don't assume.

Ask.

If the interviewer says

"You decide"

make assumptions.

---

Think in terms of workflows instead of CRUD.

Instead of

Create Order

Update Order

Delete Order

Think

Customer browses restaurants

Customer creates cart

Customer places order

Restaurant accepts order

Delivery Partner delivers order

Customer reviews order

Business workflows naturally produce the object model.

---

Communication is a capability.

Notification is one type of communication.

Communication

├── Notification
│ ├── SMS
│ ├── Email
│ ├── Push
│ └── In-App
│
├── Messaging
├── Voice
├── Video
├── Presence
└── Media Sharing

Think hierarchically.

---

Business Rules and Constraints are different.

Business Rules describe behavior.

Constraints describe limits.

---

External Systems should be abstracted through interfaces.

Don't waste interview time designing

Payment Gateway

SMS Service

Maps

Authentication

unless explicitly asked.

---

The interviewer is evaluating

* Thought Process
* Communication
* OOP
* SOLID
* Extensibility
* Design Quality

not typing speed.

---

# 6. Golden Principle

Design is not about writing classes.

Design is about understanding the problem so thoroughly that the classes almost design themselves.


****************************************************************************************************
****************************************************************************************************
****************************************************************************************************
****************************************************************************************************
****************************************************************************************************
****************************************************************************************************