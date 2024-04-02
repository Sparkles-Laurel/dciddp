# Decentralised Identity Dispatch Protocol (DCIDDP)

## Introduction
The Decentralised Identity Dispatch Protocol (DCIDDP) is a protocol that allows for dispenson of name and pronoun information in a decentralised manner, for rendering in a user interface. The protocol is designed to be simple, lightweight, and easy to implement.

## Protocol

The Protocol can function over HTTP, HTTPS, or any other protocol that supports the transmission of JSON data. The protocol is based on a few JSON data types, which are described below.

### JSON Data Types

#### The System

`System` objects represent entire plural systems and contain the following fields:

- `id` (string): A unique identifier for the system.
- `homeserver` (string): The homeserver of the system.
- `name` (string): The name of the system.
- `members` (array of `Member` objects): The members of the system.
- `collectivePronouns` (array of `Pronoun` objects): The collective pronouns of the system.
- `collectiveName` (string): The collective name of the system.
- `isSinglet` (boolean): Whether the system is a singlet system.

#### Member

`Member` objects represent individual members of a system and contain the following fields:

- `id` (string): A unique identifier for the member.
- `name` (string): The name of the member.
- `pronouns` (array of `Pronoun` objects): The pronouns of the member.

#### Pronoun

`Pronoun` objects represent pronouns and contain the following fields:

- `subject` (string): The subject pronoun.
- `object` (string): The object pronoun.
- `possessiveDeterminer` (string): The possessive determiner.
- `possessivePronoun` (string): The possessive pronoun.
- `reflexive` (string): The reflexive pronoun.

Certain pronoun pairs can be used as a shorthand for common pronouns:

- `he/him` is equivalent to `he/him/his/his/himself`.
- `she/her` is equivalent to `she/her/her/hers/herself`.
- `they/them` is equivalent to `they/them/their/theirs/themself`.
- `it/it` is equivalent to `it/it/its/its/itself`.
- `he/they` is equivalent to `he/him/his/his/himself` and `they/them/their/theirs/themself`.
- `she/they` is equivalent to `she/her/her/hers/herself` and `they/them/their/theirs/themself`.
- `he/she` is equivalent to `he/him/his/his/himself` and `she/her/her/hers/herself`.
- `he/she/they` is equivalent to `he/him/his/his/himself`, `she/her/her/hers/herself`, and `they/them/their/theirs/themself`.
- `any` is a special pronoun that can be used to indicate that any pronoun is acceptable.

#### Singlet Members

Not all people have to be parts of plural systems, but the designation of the protocol assumes everyone as a part of a system. The `isSinglet` field in the `System` object can be used to indicate that the system is a singlet system, and the `members` field must have exactly one `Member` object in that case.

### Endpoints

This is a decentralised protocol and every server-side implentation can have its own endpoints.
However, there must be a few endpoints that are common to all implementations:

- `GET /systems`: This endpoint must return a list of all systems that are registered with the server.
- `GET /system/<systemName>`: This endpoint must return the system object for the system with the name `<systemName>`.
- `GET /member/<systemName>/<memberName>`: This endpoint must return the member object for the member with the name `<memberName>` in the system with the name `<systemName>`.


The following endpoints are also required, but they require authentication:

- `POST /system/new`: This endpoint must use a partial system object that has no members to register a new system with the server.
##### Partial System Object
- `name` (string): The name of the system.
- `collectivePronouns` (array of `Pronoun` objects): The collective pronouns of the system.
- `collectiveName` (string): The collective name of the system.
- `isSinglet` (boolean): Whether the system is a singlet system.

- `POST /member/<systemName>/new`: This endpoint must use a member object to register a new member with the server.




