# ADAPTER DESIGN PATTERN — COMPLETE DEEP REVISION

Adapter is one of the most practically used structural patterns in real-world engineering.

It appears everywhere:

* payment gateway integrations
* legacy system migrations
* third-party SDK integrations
* microservices communication
* hardware drivers
* REST ↔ GraphQL transformations
* USB adapters
* cloud provider abstractions

Most beginners think Adapter simply means:

```text id="y7r2iy"
“converting interfaces”
```

But architecturally, Adapter is actually about:

```text id="dbm4v2"
making incompatible systems collaborate without modifying existing code
```

That is the real engineering purpose.

---

# Intent

Convert the interface of a class into another interface clients expect.

Adapter lets classes work together that otherwise could not because of incompatible interfaces.

---

# Core Philosophy

> “Don’t modify existing code — translate communication instead.”

---

# Fundamental Problem

Suppose your application expects:

```cpp id="8cmpr6"
PaymentProcessor.processPayment()
```

But third-party SDK provides:

```cpp id="g5ihd7"
StripeAPI.makeTransaction()
```

Interfaces incompatible.

Without Adapter:

* client changes required
* tight coupling introduced
* vendor lock-in increases
* integration logic spreads everywhere

Adapter solves this elegantly.

---

# Core Idea

Wrap incompatible object inside translator.

```text id="25ev2r"
Client → Adapter → Adaptee
```

Adapter translates:

* method names
* parameters
* protocols
* data formats

---

# Classification

Adapter is a:

```text id="4qv1m6"
Structural Design Pattern
```

Because it focuses on:

* object composition
* structural compatibility

---

# Most Important Interview Insight

Adapter does NOT add new behavior.

It:

```text id="yj2vgh"
ONLY translates existing behavior
```

This differentiates it from:

* Decorator
* Proxy
* Facade

VERY IMPORTANT.

---

# Real World Analogy

---

# Mobile Charger Adapter

Indian socket:

```text id="d2j8yu"
round pins
```

US charger:

```text id="k8q8vw"
flat pins
```

Adapter:

* does not change electricity
* does not enhance charger
* only translates compatibility

Perfect analogy.

---

# UML Mental Model

```text id="v3gvro"
Client
   |
Target Interface
   |
Adapter
   |
Adaptee
```

---

# Participants

---

# 1. Client

Uses target interface.

---

# 2. Target Interface

Expected contract.

---

# 3. Adaptee

Existing incompatible class.

---

# 4. Adapter

Bridges incompatibility.

---

# Standard Example

Suppose application expects:

```cpp id="j6thdr"
MediaPlayer.play()
```

But advanced player provides:

```cpp id="2y7e3k"
AdvancedMediaPlayer.playVlc()
```

---

# Target Interface

```cpp id="9o0ikv"
class MediaPlayer {
public:
    virtual void play(string audioType,
                      string fileName) = 0;
};
```

---

# Adaptee

```cpp id="2bdtn4"
class AdvancedMediaPlayer {
public:
    void playVlc(string fileName) {
        cout << "Playing VLC: "
             << fileName << endl;
    }
};
```

---

# Adapter

```cpp id="t3lj94"
class MediaAdapter : public MediaPlayer {

private:
    AdvancedMediaPlayer* advancedPlayer;

public:

    MediaAdapter() {
        advancedPlayer =
            new AdvancedMediaPlayer();
    }

    void play(string audioType,
              string fileName) override {

        if(audioType == "vlc") {
            advancedPlayer->playVlc(fileName);
        }
    }
};
```

---

# Runtime Flow

```text id="ocokjc"
Client
  ↓
Target Interface
  ↓
Adapter
  ↓
Adaptee
```

---

# Key Architectural Insight

Adapter enables:

```text id="v7kz9n"
integration without modification
```

This is huge in enterprise systems.

---

# TYPES OF ADAPTER

VERY IMPORTANT INTERVIEW AREA.

There are two major types:

---

# 1. OBJECT ADAPTER

(Most Common)

Uses:

```text id="y3fj03"
COMPOSITION
```

---

# Structure

```text id="cr7ozd"
Adapter HAS-A Adaptee
```

---

# Example

```cpp id="x4vg5l"
class Adapter {
    Adaptee* adaptee;
};
```

---

# Advantages

## Flexible

Can adapt multiple subclasses.

---

## Follows Composition Over Inheritance

Better scalability.

---

## Loose Coupling

Preferred modern approach.

---

# Drawbacks

Slightly more indirection.

---

# 2. CLASS ADAPTER

(Less Common)

Uses:

```text id="26cmk4"
MULTIPLE INHERITANCE
```

---

# Structure

```text id="0s3v1y"
Adapter IS-A Target
Adapter IS-A Adaptee
```

---

# Example

```cpp id="jpmc0c"
class Adapter :
    public Target,
    public Adaptee
{
};
```

---

# Advantages

Can directly override adaptee behavior.

---

# Drawbacks

## Tight Coupling

---

## Multiple Inheritance Complexity

---

## Less Flexible

---

# Interview Insight

In modern architectures:

```text id="7c8ql6"
Object Adapter is strongly preferred
```

because:

* composition safer
* inheritance brittle

---

# Adapter vs Facade

VERY IMPORTANT.

Many candidates confuse them.

---

# Adapter

Purpose:

```text id="4hcx6s"
compatibility
```

---

# Facade

Purpose:

```text id="krn8hq"
simplification
```

---

# Adapter

Changes interface.

---

# Facade

Keeps same subsystem but hides complexity.

---

# Example

## Adapter

```text id="jlwmjlwm"
USB-C → HDMI
```

---

## Facade

```text id="q5k93u"
One-button home theater startup
```

---

# Adapter vs Decorator

---

# Adapter

Changes:

```text id="jlwm"
interface compatibility
```

---

# Decorator

Adds:

```text id="6t7qwl"
new behavior dynamically
```

---

# Adapter vs Proxy

---

# Adapter

Focus:

```text id="p8ktav"
translation
```

---

# Proxy

Focus:

```text id="sm0cce"
controlled access
```

---

# Real World Enterprise Examples

---

# 1. Payment Gateway Integration

```text id="ojrw5d"
StripeAdapter
PaypalAdapter
RazorpayAdapter
```

Common interface:

```cpp id="4o8wq8"
processPayment()
```

---

# 2. Database Drivers

JDBC drivers are adapter-heavy architectures.

---

# 3. Cloud Provider SDKs

AWS/GCP/Azure normalized behind abstraction.

---

# 4. Legacy System Migration

New service layer adapts old APIs.

---

# 5. Hardware Drivers

OS adapts hardware-specific instructions.

---

# 6. Microservices Protocol Translation

REST ↔ gRPC adapters.

---

# 7. Serialization Frameworks

JSON ↔ XML ↔ ProtoBuf translation.

---

# SOLID Principles

---

# SRP

Translation isolated cleanly.

---

# OCP

New adapters added without modifying client.

---

# DIP

Client depends on abstraction.

---

# Adapter Advantages

---

# 1. Legacy Code Reuse

Huge practical benefit.

---

# 2. Loose Coupling

Client independent of vendor SDK.

---

# 3. Interoperability

Different systems collaborate.

---

# 4. Better Maintainability

Integration logic centralized.

---

# 5. Incremental Migration Support

Extremely important in enterprises.

---

# 6. Vendor Swapping Easy

Massive architectural advantage.

---

# Major Drawbacks

---

# 1. Additional Indirection

More layers.

---

# 2. Complexity Growth

Too many adapters create confusion.

---

# 3. Performance Overhead

Translation cost.

---

# 4. Overuse Can Hide Bad Architecture

Adapter soup problem.

---

# Adapter Soup

VERY IMPORTANT TERM.

Too many nested adapters:

```text id="qepzyv"
Adapter → Adapter → Adapter
```

creates:

* debugging nightmare
* tracing difficulty
* architectural opacity

---

# Recognition Clues

Use Adapter when:

* incompatible interfaces exist
* third-party SDK integration needed
* legacy systems involved
* migration happening
* multiple vendors supported

---

# Common Interview Questions

---

# Q1. Why not modify adaptee directly?

Because:

* third-party code
* legacy risk
* OCP violation
* maintainability issues

---

# Q2. Adapter uses composition or inheritance?

Primarily:

```text id="4z1kfc"
composition
```

Object Adapter preferred.

---

# Q3. Difference between Adapter and Facade?

Adapter:

```text id="jlwmjlwm"
makes incompatible systems compatible
```

Facade:

```text id="jlwm99"
simplifies subsystem usage
```

---

# Q4. Why is Adapter important in microservices?

Because heterogeneous systems:

* languages
* protocols
* formats

must interoperate.

---

# Advanced Senior-Level Insights

---

# 1. Anti-Corruption Layer (DDD)

Advanced form of Adapter.

Protects domain model from external systems.

---

# 2. Hexagonal Architecture

Ports & adapters architecture directly uses Adapter concept.

---

# 3. Adapter + Strategy Combination

Very common.

Example:

```text id="s6b4wp"
PaymentStrategy + PaymentAdapter
```

---

# 4. API Gateway Translation

Adapters normalize service contracts.

---

# 5. Reactive Systems

Adapters bridge sync ↔ async systems.

---

# Adapter in Modern Frameworks

Examples:

* Spring Adapters
* React adapters
* JDBC
* SLF4J logging abstraction
* Kafka Connect
* Retrofit converters

---

# Mental Models

---

# Simple Mental Model

```text id="7n1f4t"
Adapter is a translator between incompatible speakers.
```

---

# Another Mental Model

```text id="a0s4e6"
Client speaks English.
Adaptee speaks Japanese.
Adapter translates.
```

---

# Most Important Interview Insight

Adapter is NOT about:

```text id="n6i89h"
adding functionality
```

It is fundamentally about:

```text id="icd6u8"
enabling collaboration between incompatible components
```

without modifying existing systems.

That is the architect-level understanding.
