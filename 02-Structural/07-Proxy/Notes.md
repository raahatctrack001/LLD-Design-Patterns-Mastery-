# PROXY DESIGN PATTERN — COMPLETE DEEP REVISION

Proxy is one of the most practically important structural patterns because real systems often require:

```text id="proxy001"
controlled access to an object
```

Most beginners think Proxy means:

```text id="proxy002"
“wrapper object”
```

But architecturally, Proxy is actually about:

```text id="proxy003"
introducing an intermediary layer that controls, optimizes, secures, or manages access to a real object
```

That is the real senior-level understanding.

---

# Intent

Provide a surrogate or placeholder for another object to control access to it.

---

# Core Philosophy

> “Do not access the real object directly — mediate access through a controlling representative.”

---

# Fundamental Problem

Suppose:

* object creation expensive
* remote network call required
* access authorization needed
* caching required
* lazy loading needed
* logging/monitoring desired

Direct object access becomes problematic.

Proxy solves this by inserting:

```text id="proxy004"
controlled indirection
```

---

# Core Idea

Instead of:

```text id="proxy005"
Client → RealObject
```

we do:

```text id="proxy006"
Client → Proxy → RealObject
```

Proxy:

* intercepts requests
* applies control logic
* delegates to real object

---

# The Most Important Interview Insight

Proxy is fundamentally about:

```text id="proxy007"
access mediation
```

NOT feature enhancement.

This is VERY IMPORTANT.

---

# Classification

Proxy is a:

```text id="proxy008"
Structural Design Pattern
```

because it introduces structural indirection between client and object.

---

# UML Mental Model

```text id="proxy009"
Client
   ↓
Subject Interface
   ↓
Proxy
   ↓
Real Subject
```

---

# Participants

---

# 1. Subject Interface

Common contract.

---

# 2. Real Subject

Actual business object.

---

# 3. Proxy

Controls access to real object.

---

# 4. Client

Uses proxy transparently.

---

# MOST IMPORTANT PROPERTY

Proxy and RealObject expose:

```text id="proxy010"
same interface
```

This allows transparent substitution.

---

# Standard Example

---

# Subject Interface

```cpp id="proxy011"
class Image {
public:
    virtual void display() = 0;
    virtual ~Image() {}
};
```

---

# Real Subject

```cpp id="proxy012"
class RealImage : public Image {

private:
    string filename;

public:

    RealImage(string file)
        : filename(file) {

        loadFromDisk();
    }

    void loadFromDisk() {
        cout << "Loading "
             << filename
             << endl;
    }

    void display() override {
        cout << "Displaying "
             << filename
             << endl;
    }
};
```

---

# Proxy

```cpp id="proxy013"
class ProxyImage : public Image {

private:

    RealImage* realImage;

    string filename;

public:

    ProxyImage(string file)
        : filename(file),
          realImage(nullptr) {}

    void display() override {

        if(realImage == nullptr) {
            realImage =
                new RealImage(filename);
        }

        realImage->display();
    }
};
```

---

# Runtime Flow

```text id="proxy014"
Client
  ↓
Proxy intercepts request
  ↓
optional control logic
  ↓
Real object invocation
```

---

# Key Architectural Insight

Proxy introduces:

```text id="proxy015"
controlled transparency
```

Client often does not know:

* proxy exists
* remote calls happening
* lazy loading occurring
* permissions being checked

---

# TYPES OF PROXY

VERY IMPORTANT INTERVIEW TOPIC.

---

# 1. VIRTUAL PROXY

(MOST IMPORTANT)

---

# Purpose

```text id="proxy016"
lazy initialization of expensive objects
```

---

# Problem Solved

Suppose object:

* huge image
* large dataset
* expensive ML model

Creating object immediately wastes resources.

---

# Solution

Proxy delays creation until actually needed.

---

# Flow

```text id="proxy017"
Client requests object
      ↓
Proxy checks existence
      ↓
Create only when required
```

---

# Example

Image loading system:

* thumbnails displayed quickly
* full image loaded only on click

---

# Key Benefit

```text id="proxy018"
deferred expensive initialization
```

---

# Interview Vocabulary

Use:

* lazy loading
* deferred instantiation
* demand-driven initialization

---

# 2. PROTECTION PROXY

(VERY IMPORTANT)

---

# Purpose

```text id="proxy019"
access control and authorization
```

---

# Problem Solved

Not every user should access:

* admin panels
* sensitive APIs
* confidential documents

---

# Solution

Proxy verifies permissions before delegating.

---

# Example

```cpp id="proxy020"
class Internet {

public:
    virtual void connectTo(string site)=0;
};
```

---

# Real Subject

```cpp id="proxy021"
class RealInternet : public Internet {

public:

    void connectTo(string site) override {
        cout << "Connecting to "
             << site << endl;
    }
};
```

---

# Protection Proxy

```cpp id="proxy022"
class ProxyInternet : public Internet {

private:
    RealInternet realInternet;

public:

    void connectTo(string site) override {

        if(site == "blocked.com") {
            cout << "Access Denied\n";
            return;
        }

        realInternet.connectTo(site);
    }
};
```

---

# Key Benefit

```text id="proxy023"
centralized security enforcement
```

---

# Interview Vocabulary

Use:

* authorization layer
* access mediation
* permission enforcement

---

# 3. REMOTE PROXY

(EXTREMELY IMPORTANT)

---

# Purpose

```text id="proxy024"
represent remote distributed objects locally
```

---

# Problem Solved

Actual object exists:

* another server
* another process
* another machine

Client should interact as if object local.

---

# Solution

Proxy:

* serializes request
* performs network communication
* deserializes response

---

# Flow

```text id="proxy025"
Client
  ↓
Remote Proxy
  ↓ network
Remote Object
```

---

# Real World Examples

* RPC
* gRPC stubs
* RMI
* REST client SDKs

---

# Most Important Insight

Remote proxy hides:

```text id="proxy026"
distributed system complexity
```

---

# Interview Vocabulary

Use:

* location transparency
* network abstraction
* distributed invocation
* remote object representation

---

# 4. CACHING PROXY

---

# Purpose

```text id="proxy027"
avoid repeated expensive operations
```

---

# Example

API response caching.

---

# Flow

```text id="proxy028"
check cache
   ↓
return cached response
OR
fetch real data
```

---

# Key Benefit

```text id="proxy029"
performance optimization
```

---

# 5. LOGGING PROXY

---

# Purpose

```text id="proxy030"
monitoring and auditing
```

---

# Example

Track:

* API usage
* execution times
* failures

---

# 6. SMART REFERENCE PROXY

---

# Purpose

Adds extra management during access.

Examples:

* reference counting
* thread locking
* transaction management

---

# Example

Database transaction proxy.

---

# 7. SYNCHRONIZATION PROXY

---

# Purpose

Thread-safe access coordination.

---

# Example

Mutex locking before real invocation.

---

# 8. FIREWALL PROXY

---

# Purpose

Network filtering/security gateway.

---

# Real Example

Corporate proxy servers.

---

# Proxy vs Decorator

VERY IMPORTANT INTERVIEW QUESTION.

Most candidates confuse them.

---

# Decorator

Purpose:

```text id="proxy031"
behavior enhancement
```

---

# Proxy

Purpose:

```text id="proxy032"
access control/management
```

---

# Decorator

Adds responsibilities.

---

# Proxy

Controls interaction.

---

# Decorator

Client often aware of enhancement semantics.

---

# Proxy

Should appear transparent.

---

# MOST IMPORTANT DIFFERENCE

Decorator:

```text id="proxy033"
extends functionality
```

Proxy:

```text id="proxy034"
manages access
```

---

# Proxy vs Adapter

---

# Adapter

Focus:

```text id="proxy035"
interface translation
```

---

# Proxy

Focus:

```text id="proxy036"
access mediation
```

---

# Proxy vs Facade

---

# Facade

Simplifies:

```text id="proxy037"
subsystem usage
```

---

# Proxy

Controls:

```text id="proxy038"
single object access
```

---

# Proxy vs Flyweight

---

# Flyweight

Focus:

```text id="proxy039"
memory sharing
```

---

# Proxy

Focus:

```text id="proxy040"
access management
```

---

# Real World Enterprise Examples

---

# 1. Hibernate Lazy Loading

Virtual Proxy.

---

# 2. API Gateways

Protection + Remote Proxy.

---

# 3. CDN Systems

Caching Proxy.

---

# 4. Database Access Layers

Transaction proxies.

---

# 5. Nginx Reverse Proxy

Classic network proxy.

---

# 6. Spring AOP Proxies

Huge enterprise usage.

---

# 7. Kubernetes Service Proxies

Distributed communication abstraction.

---

# 8. Browser Proxies

Security + caching.

---

# Proxy in Distributed Systems

VERY IMPORTANT.

Modern distributed systems heavily depend on proxies:

* Envoy Proxy
* API Gateway
* Reverse Proxy
* Service Mesh

---

# Proxy Enables Transparency

Client feels:

```text id="proxy041"
local invocation
```

while actual operations may involve:

* network
* auth
* retries
* caching
* monitoring

---

# SOLID Principles

---

# SRP

Access management isolated cleanly.

---

# OCP

New proxies added without modifying real object.

---

# DIP

Clients depend on abstractions.

---

# Major Advantages

---

# 1. Controlled Access

Biggest advantage.

---

# 2. Lazy Loading

---

# 3. Security Enforcement

---

# 4. Performance Optimization

---

# 5. Remote Invocation Transparency

---

# 6. Monitoring/Auditing Support

---

# 7. Centralized Cross-Cutting Concerns

---

# Major Drawbacks

---

# 1. Increased Indirection

Extra layer.

---

# 2. Performance Overhead

Additional processing.

---

# 3. Complexity Growth

Too many proxies create opacity.

---

# 4. Debugging Difficulty

Harder tracing.

---

# 5. Distributed Failure Hidden

Remote proxies may mask network latency/failure.

---

# Recognition Clues

Use Proxy when:

* access control needed
* lazy loading required
* remote communication hidden
* caching required
* monitoring needed
* expensive object management involved

---

# Common Interview Questions

---

# Q1. What problem does Proxy solve?

```text id="proxy042"
controlled and managed object access
```

---

# Q2. Difference between Proxy and Decorator?

Proxy:

```text id="proxy043"
controls access
```

Decorator:

```text id="proxy044"
adds behavior
```

---

# Q3. Why does proxy implement same interface?

For:

```text id="proxy045"
transparent substitution
```

---

# Q4. What is Virtual Proxy?

Lazy-loading proxy delaying expensive object creation.

---

# Q5. What is Remote Proxy?

Local representative for distributed remote object.

---

# Q6. Why are proxies important in microservices?

Because distributed systems require:

* location transparency
* retries
* auth
* monitoring
* caching

---

# Advanced Senior-Level Insights

---

# 1. AOP Frameworks Use Dynamic Proxies

Spring heavily relies on proxies.

---

# 2. Service Meshes Are Proxy Architectures

Envoy sidecars = advanced remote proxies.

---

# 3. Reverse Proxies Power Internet Infrastructure

Nginx, HAProxy, Cloudflare.

---

# 4. Database Lazy Loading Uses Virtual Proxy

ORM optimization strategy.

---

# 5. Smart Proxies Add Reliability Features

Retries/circuit breakers/rate limiting.

---

# 6. Dynamic Proxy Generation

Languages/frameworks generate proxies at runtime.

---

# 7. RPC Frameworks Depend On Remote Proxies

gRPC stubs conceptually proxies.

---

# Common Mistakes

---

# 1. Confusing Proxy with Decorator

Most common error.

---

# 2. Embedding Business Logic In Proxy

Proxy should manage access concerns.

---

# 3. Excessive Proxy Chaining

Creates opaque architectures.

---

# 4. Ignoring Network Failure In Remote Proxy

Distributed systems unreliable.

---

# 5. Mutable Shared Proxy State

Concurrency issues possible.

---

# Mental Models

---

# Simple Mental Model

```text id="proxy046"
Security guard controlling building access.
```

---

# Another Mental Model

```text id="proxy047"
Receptionist forwarding calls to executive only when allowed.
```

---

# Virtual Proxy Mental Model

```text id="proxy048"
Netflix loads full movie only when you click play.
```

---

# Remote Proxy Mental Model

```text id="proxy049"
Calling someone abroad feels like local interaction.
```

Network complexity hidden.

---

# Most Important Interview Insight

Proxy is NOT fundamentally about:

```text id="proxy050"
“wrapping objects”
```

It is about:

```text id="proxy051"
mediating and controlling access to objects
```

for purposes such as:

* lazy loading
* authorization
* remote communication
* caching
* monitoring
* synchronization

while maintaining:

```text id="proxy052"
transparent client interaction
```

That is the architect-level understanding.
