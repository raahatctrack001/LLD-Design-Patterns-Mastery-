# TEMPLATE METHOD DESIGN PATTERN — COMPLETE DEEP REVISION

Template Method is one of the most foundational behavioral patterns because it solves a very important architectural problem:

```text id="template001"
duplication of invariant workflow structure
```

Most beginners think Template Method means:

```text id="template002"
“base class with overridable methods”
```

But architecturally, Template Method is actually about:

```text id="template003"
defining an invariant algorithm skeleton while allowing controlled customization of individual steps
```

That is the real senior-level understanding.

---

# Intent

Define the skeleton of an algorithm in a method, deferring some steps to subclasses.

Template Method lets subclasses redefine certain steps without changing the algorithm’s overall structure.

---

# Core Philosophy

> “Keep workflow structure fixed, allow step-level variation.”

---

# Fundamental Problem

Suppose multiple document parsers:

* PDF parser
* CSV parser
* JSON parser

All follow:

```text id="template004"
Open File
   ↓
Read Data
   ↓
Parse Content
   ↓
Validate
   ↓
Close File
```

Naive approach:

* duplicate workflow everywhere
* inconsistent ordering
* maintenance difficult
* algorithm integrity fragile

This creates:

```text id="template005"
workflow duplication and inconsistency
```

Template Method solves this elegantly.

---

# Core Idea

Instead of:

```text id="template006"
every subclass defining complete algorithm
```

we do:

```text id="template007"
base class defines workflow skeleton
```

while subclasses customize:

* specific steps
* optional behavior
* implementation details

---

# The Most Important Interview Insight

Template Method is fundamentally about:

```text id="template008"
controlled algorithm extensibility
```

This is the heart of the pattern.

---

# Classification

Template Method is a:

```text id="template009"
Behavioral Design Pattern
```

because it governs algorithm execution behavior.

---

# UML Mental Model

```text id="template010"
Abstract Base Class
   ↓
Template Method
   ↓
Primitive Operations
   ↓
Concrete Subclasses
```

---

# Participants

---

# 1. Abstract Class

Defines template method.

---

# 2. Template Method

Defines fixed algorithm structure.

---

# 3. Primitive Operations

Customizable steps.

---

# 4. Concrete Subclasses

Implement variable behavior.

---

# MOST IMPORTANT INSIGHT

Template Method separates:

```text id="template011"
INVARIANT WORKFLOW STRUCTURE
        FROM
VARIANT IMPLEMENTATION STEPS
```

---

# Standard Example — Beverage Preparation

---

# Abstract Class

```cpp id="template012"
class Beverage {

public:

    void prepareRecipe() {

        boilWater();

        brew();

        pourInCup();

        addCondiments();
    }

    virtual void brew() = 0;

    virtual void addCondiments() = 0;

    void boilWater() {

        cout << "Boiling Water\n";
    }

    void pourInCup() {

        cout << "Pouring into cup\n";
    }

    virtual ~Beverage() {}
};
```

---

# Concrete Class

```cpp id="template013"
class Tea : public Beverage {

public:

    void brew() override {

        cout << "Steeping Tea\n";
    }

    void addCondiments() override {

        cout << "Adding Lemon\n";
    }
};
```

---

# Another Concrete Class

```cpp id="template014"
class Coffee : public Beverage {

public:

    void brew() override {

        cout << "Brewing Coffee\n";
    }

    void addCondiments() override {

        cout << "Adding Sugar and Milk\n";
    }
};
```

---

# Client

```cpp id="template015"
int main() {

    Beverage* tea =
        new Tea();

    tea->prepareRecipe();
}
```

---

# Runtime Flow

```text id="template016"
Template method invoked
        ↓
fixed workflow executes
        ↓
subclass-specific steps called polymorphically
```

---

# Key Architectural Insight

Template Method preserves:

```text id="template017"
algorithm integrity
```

while still enabling:

```text id="template018"
controlled extensibility
```

---

# Why Template Method Exists

Without Template Method:

* duplicate workflows
* inconsistent processing order
* scattered algorithm structure
* maintenance difficult

Template Method enables:

* reusable workflows
* centralized process control
* customizable steps

---

# Hollywood Principle

VERY IMPORTANT.

Template Method strongly follows:

```text id="template019"
“Don’t call us, we’ll call you.”
```

Subclasses do NOT control workflow.

Base class calls subclass methods.

This is huge interview vocabulary.

---

# Inversion Of Control (IoC)

VERY IMPORTANT.

Framework controls execution flow.

Subclass only injects behavior.

Template Method is early form of:

```text id="template020"
IoC architecture
```

---

# Hooks

VERY IMPORTANT INTERVIEW TOPIC.

Hooks are:

```text id="template021"
optional overridable extension points
```

---

# Example

```cpp id="template022"
virtual bool customerWantsCondiments() {

    return true;
}
```

---

# Template Method With Hook

```cpp id="template023"
void prepareRecipe() {

    boilWater();

    brew();

    pourInCup();

    if(customerWantsCondiments()) {

        addCondiments();
    }
}
```

---

# Hook Benefits

* optional customization
* algorithm flexibility
* extension without structural change

---

# Primitive Operations

Customizable steps are called:

```text id="template024"
primitive operations
```

VERY IMPORTANT vocabulary.

---

# Algorithm Skeleton Preservation

Critical idea.

Subclasses CANNOT alter:

* ordering
* critical steps
* workflow integrity

unless base class allows it.

---

# Template Method vs Strategy

MOST IMPORTANT INTERVIEW QUESTION.

---

# Template Method

Uses:

```text id="template025"
inheritance
```

---

# Strategy

Uses:

```text id="template026"
composition
```

---

# Template Method

Algorithm structure fixed.

---

# Strategy

Entire algorithm replaceable.

---

# Template Method

Variation at:

```text id="template027"
step level
```

---

# Strategy

Variation at:

```text id="template028"
whole behavior level
```

---

# MOST IMPORTANT DIFFERENCE

Template Method:

```text id="template029"
controls workflow structure
```

Strategy:

```text id="template030"
swaps algorithms dynamically
```

---

# Template Method vs Factory Method

VERY IMPORTANT.

Factory Method often appears INSIDE Template Method.

---

# Template Method

Defines workflow.

---

# Factory Method

Creates objects.

---

# Example

```text id="template031"
Game loop fixed
Enemy creation customizable
```

---

# Template Method vs State

---

# State

Behavior changes dynamically via state objects.

---

# Template Method

Workflow structure statically inherited.

---

# Real World Use Cases

---

# 1. Spring Framework Lifecycle

* initialize
* validate
* execute
* cleanup

---

# 2. Servlet Frameworks

doGet/doPost hooks.

---

# 3. Game Engines

Game loop fixed.

---

# 4. Compiler Pipelines

Lex → parse → optimize → generate.

---

# 5. Data Processing Pipelines

ETL workflows.

---

# 6. Machine Learning Pipelines

Preprocess → train → evaluate.

---

# 7. Build Systems

Compile → test → package → deploy.

---

# 8. UI Rendering Frameworks

Lifecycle hooks.

---

# Framework Design

VERY IMPORTANT SENIOR INSIGHT.

Frameworks heavily use Template Method because they need:

```text id="template032"
framework-controlled execution flow
```

while allowing:

```text id="template033"
application-specific customization
```

---

# Spring Framework Example

Spring internally controls:

* bean lifecycle
* initialization sequence
* transaction workflow

Developers override hooks.

---

# Game Loop Architecture

Classic template method:

```text id="template034"
Initialize
Update
Render
Cleanup
```

Fixed structure.

---

# Compiler Architecture

Compilation stages fixed:

* lexing
* parsing
* semantic analysis
* optimization

Individual behaviors customizable.

---

# Dependency Inversion

Base class depends on:

```text id="template035"
abstract primitive operations
```

not concrete implementations.

---

# SOLID Principles

---

# SRP

Workflow separated from step implementations.

---

# OCP

New subclasses extend behavior.

---

# DIP

Base class relies on abstractions.

---

# Major Advantages

---

# 1. Eliminates Workflow Duplication

Biggest advantage.

---

# 2. Preserves Algorithm Integrity

---

# 3. Encourages Reuse

---

# 4. Centralized Workflow Control

---

# 5. Controlled Extensibility

---

# 6. Framework-Friendly Architecture

---

# 7. Strong Lifecycle Modeling

---

# Major Drawbacks

---

# 1. Inheritance Coupling

Tight subclass dependency.

---

# 2. Rigid Workflow Structure

Hard to alter dynamically.

---

# 3. Fragile Base Class Problem

Base changes affect subclasses.

---

# 4. Limited Runtime Flexibility

Compared to Strategy.

---

# 5. Deep Inheritance Complexity

Can become difficult.

---

# Recognition Clues

Use Template Method when:

* workflow structure fixed
* steps vary slightly
* duplicate algorithm structures exist
* lifecycle consistency important
* frameworks control execution flow

---

# Common Interview Questions

---

# Q1. What problem does Template Method solve?

```text id="template036"
duplicate workflow structure with varying steps
```

---

# Q2. Difference between Strategy and Template Method?

Strategy:

```text id="template037"
composition-based algorithm replacement
```

Template Method:

```text id="template038"
inheritance-based step customization
```

---

# Q3. What is a hook?

Optional overridable extension point.

---

# Q4. What is Hollywood Principle?

```text id="template039"
“Don’t call us, we’ll call you.”
```

Framework controls flow.

---

# Q5. Biggest risk in Template Method?

Inheritance rigidity.

---

# Advanced Senior-Level Insights

---

# 1. Frameworks Depend Heavily On Template Method

Spring/Servlets/Game engines.

---

# 2. IoC Containers Extend Template Concepts

Framework owns lifecycle.

---

# 3. Compiler Pipelines Use Fixed Workflow Models

---

# 4. Workflow Engines Often Combine Template + Strategy

Fixed pipeline + pluggable steps.

---

# 5. Modern Functional Pipelines Sometimes Replace Template Method

Composition over inheritance trend.

---

# 6. Reactive Frameworks Use Lifecycle Hooks Extensively

---

# 7. Template Method Often Appears With Factory Method

Object creation customizable inside workflow.

---

# Common Mistakes

---

# 1. Confusing Strategy with Template Method

Most common mistake.

---

# 2. Excessive Inheritance Depth

Makes system rigid.

---

# 3. Exposing Too Many Hooks

Weakens algorithm integrity.

---

# 4. Embedding Too Much Logic In Primitive Operations

Breaks SRP.

---

# 5. Making Template Method Overridable

Dangerous workflow corruption.

---

# Mental Models

---

# Simple Mental Model

```text id="template040"
Recipe structure fixed, ingredients customizable.
```

---

# Another Mental Model

```text id="template041"
Game engine controls loop, developers customize rendering behavior.
```

---

# Framework Mental Model

```text id="template042"
Spring framework controls lifecycle while application injects custom steps.
```

---

# Most Important Interview Insight

Template Method is NOT fundamentally about:

```text id="template043"
“abstract classes with virtual methods”
```

It is about:

```text id="template044"
preserving invariant workflow structure while enabling controlled customization of specific steps
```

so that:

* workflows remain consistent
* duplication disappears
* frameworks control execution
* extensibility becomes structured

That is the architect-level understanding.


Some highly realistic and professional examples for the Template Method Pattern are:

---

# 1. Backend Request Processing Pipeline (BEST for Web Dev)

Very interview-professional.

Template:

```txt id="jlwm9w"
authenticate()
validate()
processBusinessLogic()
sendResponse()
logRequest()
```

Different APIs customize:

* payment API
* auth API
* order API

while overall flow remains fixed.

---

# 2. Spring Boot / Express Middleware Lifecycle

Framework internally defines:

```txt id="jlwmx1"
receive request
parse request
execute middleware
handle controller
send response
```

Developers override/customize certain steps.

Very industry-realistic.

---

# 3. Data ETL Pipeline

Used heavily in data engineering.

Fixed workflow:

```txt id="jlwmm8"
extractData()
transformData()
validateData()
loadData()
```

Different pipelines customize transformation rules.

Very professional system-design example.

---

# 4. Payment Processing Workflow

Flow fixed:

```txt id="jlwm4r"
validatePayment()
fraudCheck()
deductAmount()
sendReceipt()
```

Different gateways implement differently:

* Stripe
* PayPal
* Razorpay

Excellent fintech example.

---

# 5. Game Engine Rendering Loop

Used in game engines.

Fixed algorithm:

```txt id="jlwm5g"
initialize()
loadAssets()
update()
render()
cleanup()
```

Games customize update/render logic.

Very strong C++ example.

---

# 6. CI/CD Deployment Pipeline

Modern DevOps example.

Fixed pipeline:

```txt id="jlwm6c"
build()
runTests()
deploy()
notify()
rollbackIfFailed()
```

Different deployment strategies customize steps.

Extremely professional.

---

# 7. Authentication Framework

Fixed workflow:

```txt id="jlwm2t"
collectCredentials()
validate()
generateToken()
sendResponse()
```

OAuth, JWT, Session Auth vary internally.

Very realistic backend example.

---

# 8. Compiler Architecture

Classic CS example.

Fixed steps:

```txt id="jlwm0s"
lexicalAnalysis()
parsing()
semanticAnalysis()
optimization()
codeGeneration()
```

Different compilers customize implementation.

---

# Best Choice For Interviews

If targeting:

| Domain           | Best Example                |
| ---------------- | --------------------------- |
| Web Dev          | Request Processing Pipeline |
| Backend          | Authentication System       |
| Fintech          | Payment Processing          |
| DevOps           | CI/CD Pipeline              |
| Game Dev         | Game Engine Loop            |
| Data Engineering | ETL Pipeline                |

---

# Most Professional Overall

This one is strongest:

```txt id="jlwm8v"
Backend API Request Lifecycle
```

because it demonstrates:

* framework architecture
* hooks
* extensibility
* inversion of control
* scalable backend design

which interviewers immediately recognize as industry-grade understanding.
