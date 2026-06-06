# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [1.0.0] - 2026-06-05

### Added

- Interactive console menu for security incident management
- Incident registration with field validation (description, threat actor, type, priority)
- Automatic SOC team assignment based on incident priority
- Initial status differentiation: critical starts "En Curso/Asignado", others "Pendiente"
- Unique ID generation with format `INC-P{priority}-{counter}` (e.g. `INC-P1-001`)
- Full incident listing display
- Statistical summary grouped by priority level
- Custom responsible assignment for medium-priority (3) incidents
- Modular project structure with separate headers and source files
- CMake build system with C++20 standard
