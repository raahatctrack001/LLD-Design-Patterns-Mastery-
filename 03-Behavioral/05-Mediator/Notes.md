# MEDIATOR DESIGN PATTERN — COMPLETE DEEP REVISION

Mediator is one of the most architecturally important behavioral patterns because it solves a very dangerous system problem:

```text id="mediator001"
chaotic many-to-many object communication
```

Most beginners think Mediator means:

```text id="mediator002"
“middleman object”
```

But architecturally, Mediator is actually about:

```text id="mediator003"
centralizing interaction coordination between collaborating objects
```

That is the real senior-level understanding.

---

# Intent

Define an object that encapsulates how a set of objects interact.

Mediator promotes loose coupling by preventing objects from referring to each other explicitly.

---

# Core Philosophy

> “Objects should communicate through a coordinator, not directly.”

---

# Fundamental Problem

Suppose chat application has:

* User
* NotificationService
* MessageService
* PresenceService
* LoggingService

Naive design:

```text id="mediator004"
User ↔ NotificationService
User ↔ PresenceService
MessageService ↔ LoggingService
PresenceService ↔ NotificationService
```

As system grows:

* dependencies explode
* communication tangled
* maintenance impossible
* ripple-effect modifications occur

This creates:

```text id="mediator005"
communication graph explosion
```

Mediator solves this elegantly.

---

# Core Idea

Instead of:

```text id="mediator006"
objects communicating directly
```

all communication goes through:

```text id="mediator007"
centralized mediator
```

---

# The Most Important Interview Insight

Mediator is fundamentally about:

```text id="mediator008"
interaction orchestration
```

This is the heart of the pattern.

---

# Classification

Mediator is a:

```text id="mediator009"
Behavioral Design Pattern
```

because it coordinates object communication behavior.

---

# UML Mental Model

```text id="mediator010"
Colleague Objects
      ↓
   Mediator
      ↑
Colleague Objects
```

---

# Participants

---

# 1. Mediator Interface

Defines communication contract.

---

# 2. Concrete Mediator

Coordinates interactions.

---

# 3. Colleague Objects

Communicate via mediator.

---

# MOST IMPORTANT INSIGHT

Mediator separates:

```text id="mediator011"
COMMUNICATION LOGIC
        FROM
BUSINESS OBJECTS
```

---

# Standard Example — Chat Room

---

# Mediator Interface

```cpp id="mediator012"
class ChatMediator {

public:

    virtual void sendMessage(
        string msg,
        class User* user
    ) = 0;

    virtual void addUser(
        User* user
    ) = 0;

    virtual ~ChatMediator() {}
};
```

---

# Colleague

```cpp id="mediator013"
class User {

protected:

    ChatMediator* mediator;

    string name;

public:

    User(
        ChatMediator* med,
        string n
    ) : mediator(med), name(n) {}

    virtual void send(
        string msg
    ) = 0;

    virtual void receive(
        string msg
    ) = 0;
};
```

---

# Concrete Colleague

```cpp id="mediator014"
class ChatUser : public User {

public:

    ChatUser(
        ChatMediator* med,
        string n
    ) : User(med, n) {}

    void send(
        string msg
    ) override {

        mediator->sendMessage(
            msg,
            this
        );
    }

    void receive(
        string msg
    ) override {

        cout << name
             << " received: "
             << msg << endl;
    }
};
```

---

# Concrete Mediator

```cpp id="mediator015"
class ChatRoom
    : public ChatMediator {

private:

    vector<User*> users;

public:

    void addUser(
        User* user
    ) override {

        users.push_back(user);
    }

    void sendMessage(
        string msg,
        User* sender
    ) override {

        for(auto user : users) {

            if(user != sender) {

                user->receive(msg);
            }
        }
    }
};
```

---

# Runtime Flow

```text id="mediator016"
Colleague sends request
        ↓
Mediator receives event
        ↓
Mediator coordinates responses
        ↓
Other colleagues updated
```

---

# Key Architectural Insight

Mediator centralizes:

```text id="mediator017"
collaboration complexity
```

This is extremely important.

---

# Why Mediator Exists

Without Mediator:

* objects tightly coupled
* dependency graph massive
* communication logic duplicated
* changes ripple everywhere

Mediator enables:

* centralized coordination
* loose coupling
* simplified dependencies

---

# Communication Topology

VERY IMPORTANT.

---

# Without Mediator

```text id="mediator018"
many-to-many communication graph
```

Complexity:

```text id="mediator019"
O(n²)
```

---

# With Mediator

```text id="mediator020"
star topology communication
```

Complexity:

```text id="mediator021"
O(n)
```

This is a MASSIVE architectural insight.

---

# Colleague Isolation

Colleague objects:

* know only mediator
* not each other

Huge decoupling benefit.

---

# Centralized Workflow Coordination

Mediator often acts as:

```text id="mediator022"
workflow orchestrator
```

---

# Event Coordination

Mediator commonly coordinates:

* events
* notifications
* workflows
* distributed actions

---

# Interview Vocabulary

Use these naturally:

* interaction orchestration
* centralized communication hub
* collaboration decoupling
* coordination abstraction
* communication topology reduction
* workflow mediation
* colleague isolation
* event coordination layer

---

# Mediator vs Observer

VERY IMPORTANT INTERVIEW QUESTION.

---

# Observer

Focus:

```text id="mediator023"
broadcast notifications
```

---

# Mediator

Focus:

```text id="mediator024"
interaction coordination
```

---

# Observer

One-to-many updates.

---

# Mediator

Many-to-many collaboration management.

---

# Observer

Publisher/subscriber relationship.

---

# Mediator

Peer interaction orchestration.

---

# MOST IMPORTANT DIFFERENCE

Observer:

```text id="mediator025"
notification-centric
```

Mediator:

```text id="mediator026"
workflow-centric
```

---

# Mediator vs Facade

VERY IMPORTANT.

---

# Facade

Simplifies:

```text id="mediator027"
subsystem access
```

---

# Mediator

Coordinates:

```text id="mediator028"
peer interactions
```

---

# Facade

Mostly one-way usage.

---

# Mediator

Bidirectional communication.

---

# Mediator vs Command

---

# Command

Encapsulates executable actions.

---

# Mediator

Coordinates communication flow.

---

# Mediator vs Controller

Senior-level distinction.

Controllers often act like:

```text id="mediator029"
application-specific mediators
```

especially in GUI systems.

---

# Real World Examples

---

# 1. Chat Applications

Classic mediator example.

---

# 2. Air Traffic Control Systems

Aircraft communicate through ATC.

---

# 3. GUI Dialog Systems

Buttons/textboxes interact via dialog mediator.

---

# 4. Microservice Orchestration

Saga coordinators.

---

# 5. Workflow Engines

Temporal/Camunda orchestration.

---

# 6. Smart Home Hubs

Devices coordinated centrally.

---

# 7. Multiplayer Game Servers

Players communicate through server mediator.

---

# 8. Event Orchestrators

Enterprise integration systems.

---

# Air Traffic Control Analogy

VERY IMPORTANT MENTAL MODEL.

Without mediator:

```text id="mediator030"
every plane talks to every plane
```

Chaos.

With mediator:

```text id="mediator031"
all communication through control tower
```

Perfect analogy.

---

# GUI Systems

Classic mediator-heavy systems.

Example:

* button click disables textbox
* checkbox enables dropdown

Components coordinate via:

```text id="mediator032"
dialog mediator
```

not direct references.

---

# Saga Orchestration

VERY IMPORTANT MODERN ANALOGY.

Distributed transaction coordinators behave like:

```text id="mediator033"
distributed mediators
```

---

# Orchestration vs Choreography

Senior-level distributed systems insight.

---

# Mediator

Represents:

```text id="mediator034"
orchestration
```

central coordinator.

---

# Observer/Event Bus

Represents:

```text id="mediator035"
choreography
```

distributed event reactions.

---

# SOLID Principles

---

# SRP

Communication centralized separately.

---

# OCP

New colleagues added easily.

---

# DIP

Colleagues depend on mediator abstraction.

---

# Major Advantages

---

# 1. Reduced Coupling

Biggest advantage.

---

# 2. Simplified Communication

---

# 3. Centralized Coordination Logic

---

# 4. Easier Maintenance

---

# 5. Better Scalability

---

# 6. Cleaner Dependency Graph

---

# 7. Improved Reusability Of Colleagues

---

# Major Drawbacks

---

# 1. God Mediator Risk

VERY IMPORTANT.

Mediator may become:

```text id="mediator036"
massive coordination monster
```

---

# 2. Centralized Complexity

All workflows accumulate.

---

# 3. Hard Debugging

Mediator logic may become opaque.

---

# 4. Performance Bottleneck

Single coordination hub.

---

# 5. Excessive Indirection

Communication path longer.

---

# Recognition Clues

Use Mediator when:

* objects excessively interconnected
* communication graph exploding
* workflow coordination centralized
* many-to-many interactions exist
* dependency graph too complex

---

# Common Interview Questions

---

# Q1. What problem does Mediator solve?

```text id="mediator037"
many-to-many communication complexity
```

---

# Q2. Difference between Mediator and Observer?

Observer:

```text id="mediator038"
broadcast notifications
```

Mediator:

```text id="mediator039"
centralized interaction coordination
```

---

# Q3. Why does Mediator reduce coupling?

Because colleagues depend only on mediator.

---

# Q4. Biggest risk of Mediator?

God object problem.

---

# Q5. Why is Mediator important in distributed systems?

Because orchestration requires centralized workflow coordination.

---

# Advanced Senior-Level Insights

---

# 1. Saga Coordinators Are Mediators

Distributed transaction orchestration.

---

# 2. Kubernetes Controllers Behave Mediator-Like

Cluster coordination.

---

# 3. API Gateways Sometimes Act As Mediators

Cross-service orchestration.

---

# 4. GUI Frameworks Heavily Use Mediators

Dialog coordination.

---

# 5. CQRS Orchestrators Use Mediation

Workflow coordination.

---

# 6. Enterprise Service Bus (ESB)

Mediator-style architecture.

---

# 7. Reactive Workflow Engines

Central orchestration hubs.

---

# Common Mistakes

---

# 1. Confusing Mediator with Observer

Most common mistake.

---

# 2. Creating God Mediators

Huge anti-pattern.

---

# 3. Embedding Business Logic Excessively

Mediator should coordinate, not own everything.

---

# 4. Overusing For Simple Systems

Direct communication may be simpler.

---

# 5. Circular Mediation Dependencies

Dangerous complexity.

---

# Mental Models

---

# Simple Mental Model

```text id="mediator040"
Air traffic control coordinating airplanes.
```

---

# Another Mental Model

```text id="mediator041"
WhatsApp server routing communication between users.
```

---

# Distributed System Mental Model

```text id="mediator042"
Saga orchestrator coordinating microservices.
```

---

# Most Important Interview Insight

Mediator is NOT fundamentally about:

```text id="mediator043"
“middleman communication”
```

It is about:

```text id="mediator044"
centralizing collaboration and workflow coordination
```

so that:

* objects remain loosely coupled
* communication graphs stay manageable
* workflows become orchestrated
* interaction complexity becomes centralized

That is the architect-level understanding.
