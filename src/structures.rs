mod data {
    use std::collections::HashMap;

    /// Represents an entire plural system
    // - `id` (string): A unique identifier for the system.
    // - `homeserver` (string): The homeserver of the system.
    // - `name` (string): The name of the system.
    // - `members` (array of `Member` objects): The members of the system.
    // -`collectivePronouns` (array of `Pronoun` objects): The collective pronouns of the system.
    // - `collectiveName` (string): The collective name of the system.
    // - `isSinglet` (boolean): Whether the system is a singlet system.
    struct PluralSystem {
        id: String,
        homeserver: String,
        name: String,
        members: Vec<Member>,
        collective_pronouns: Vec<Pronoun>,
        collective_name: String,
        is_singlet: bool,
    }

    /// Represents a member of a plural system
    /// - `id` (string): A unique identifier for the member.
    /// - `name` (string): The name of the member.
    /// - `pronouns` (array of `Pronoun` objects): The pronouns of the member.
    /// - `description` (string): A description of the member.
    /// - `addiitionalInfo` (Map of string against string): Additional information about the member.
    struct Member {
        id: String,
        name: String,
        pronouns: Vec<Pronoun>,
        description: String,
        additional_info: HashMap<String, String>,
    }

    /// Represnts pronouns
    /// - `subject` (string): The subject pronoun.
    /// - `object` (string): The object pronoun.
    /// - `possessiveDeterminer` (string): The possessive determiner.
    /// - `possessivePronoun` (string): The possessive pronoun.
    /// - `reflexive` (string): The reflexive pronoun.
    /// - `plural` (boolean): Whether the pronouns are plural.
    struct Pronoun {
        subject: String,
        object: String,
        possessive_determiner: String,
        possessive_pronoun: String,
        reflexive: String,
        plural: bool,
    }

    impl Pronoun {
        /// some common pronouns as functions
        
        pub fn they_them() -> Pronoun {
            Pronoun {
                subject: "they".to_string(),
                object: "them".to_string(),
                possessive_determiner: "their".to_string(),
                possessive_pronoun: "theirs".to_string(),
                reflexive: "themselves".to_string(),
                plural: true,
            }
        }

        pub fn he_him() -> Pronoun {
            Pronoun {
                subject: "he".to_string(),
                object: "him".to_string(),
                possessive_determiner: "his".to_string(),
                possessive_pronoun: "his".to_string(),
                reflexive: "himself".to_string(),
                plural: false,
            }
        }

        pub fn she_her() -> Pronoun {
            Pronoun {
                subject: "she".to_string(),
                object: "her".to_string(),
                possessive_determiner: "her".to_string(),
                possessive_pronoun: "hers".to_string(),
                reflexive: "herself".to_string(),
                plural: false,
            }
        }

        pub fn it_its() -> Pronoun {
            Pronoun {
                subject: "it".to_string(),
                object: "it".to_string(),
                possessive_determiner: "its".to_string(),
                possessive_pronoun: "its".to_string(),
                reflexive: "itself".to_string(),
                plural: false,
            }
        }
        
        pub fn new(subject: &str, object: &str, possessive_determiner: &str, possessive_pronoun: &str, reflexive: &str, plural: bool) -> Pronoun {
            Pronoun {
                subject: subject.to_string(),
                object: object.to_string(),
                possessive_determiner: possessive_determiner.to_string(),
                possessive_pronoun: possessive_pronoun.to_string(),
                reflexive: reflexive.to_string(),
                plural: plural,
            }
        }

    }

}