# Claude Anthropic Code Assistant: Comprehensive Documentation

## Table of Contents

1. [Overview](#overview)
2. [Key Features](#key-features)
3. [Availability and Access](#availability-and-access)
4. [Pricing](#pricing)
5. [API Capabilities](#api-capabilities)
6. [Technical Specifications](#technical-specifications)
7. [Platform and Language Support](#platform-and-language-support)
8. [Security and Integration](#security-and-integration)
9. [Agent Capabilities](#agent-capabilities)
10. [Strengths](#strengths)
11. [Weaknesses and Limitations](#weaknesses-and-limitations)
12. [Use Cases](#use-cases)
13. [Integration Guide](#integration-guide)
14. [Comparison with Competitors](#comparison-with-competitors)
15. [Best Practices](#best-practices)
16. [Resources and Links](#resources-and-links)

---

## Overview

Claude Code is an agentic coding assistant developed by Anthropic, purpose-built for modern software development workflows. Launched in October 2025, it represents a significant advancement in AI-powered code assistance, combining a powerful API with a web application and IDE integration. Claude Code is designed to handle complex development tasks through multi-step reasoning and autonomous execution, making it a comprehensive tool for feature development, bug fixing, refactoring, and codebase navigation.

### Key Positioning

- **Target Users**: Enterprise developers, teams, and organizations requiring sophisticated code assistance
- **Primary Value**: Deep codebase understanding enabled by massive context window and robust API capabilities
- **Market Position**: Premium tier AI coding assistant with focus on enterprise security and advanced features

---

## Key Features

### Core Features

1. **Agentic Coding Assistance**
   - Multi-step task handling and execution
   - Autonomous feature implementation and refactoring
   - Code review automation
   - Complex task transformation and optimization

2. **Advanced API Tools**
   - Code execution in sandboxed environment
   - MCP (Model Context Protocol) connector support
   - Files API for efficient document management
   - Extended prompt caching for cost optimization

3. **Web Application Interface**
   - Browser-based access for easy onboarding
   - Real-time code assistance and suggestions
   - Interactive development workflows

4. **IDE Integration**
   - Native support in JetBrains IDEs
   - Claude Code web application for standalone use
   - Seamless workflow integration

5. **Data Analysis Capabilities**
   - Python code execution in sandboxed environment
   - Data visualization generation
   - Dataset cleaning and transformation
   - Direct insights generation within API requests

---

## Availability and Access

### Distribution Channels

| Channel | Type | Status | Availability |
|---------|------|--------|--------------|
| Web Application | Browser-based | Launched Oct 2025 | All subscribers |
| IDE Integration | JetBrains IDEs | Available | Pro, Max, Team plans |
| SDK | TypeScript, Python, CLI | Available | Authorized developers |
| Team Plans | Cloud-based | Available | Enterprise organizations |

### Subscription Tiers

Claude Code is exclusively available through Anthropic's subscription service. There is no free tier available.

**Available to:**

- **Claude Pro** ($20/month)
- **Claude Max** ($100/month)
- **Team Plans** (Custom pricing for organizations)

---

## Pricing

### Subscription-Based Access

Claude Code is accessible through three primary subscription tiers:

#### Claude Pro

- **Cost**: $20/month
- **Best For**: Individual developers
- **Includes**: Web application access, standard API limits
- **Context Window**: 200K tokens free tier, extended caching available

#### Claude Max

- **Cost**: $100/month
- **Best For**: Power users and developers with intensive needs
- **Includes**: Increased API limits, extended context access, priority support
- **Context Window**: Full 1 million token access

#### Team Plans

- **Cost**: Custom pricing per user
- **Best For**: Organizations and enterprises
- **Includes**: Advanced security features, audit trails, API management, team collaboration tools
- **Context Window**: Full 1 million token access for all team members

### API Pricing Model

Claude Code API operates on a token-based pricing model:

- **Input tokens**: Lower cost per token for context processing
- **Output tokens**: Higher cost per token for generated content
- **Extended caching**: Available for both Pro and Max tiers with 1-hour TTL option

### Cost Optimization Features

1. **Extended Prompt Caching**
   - Standard 5-minute TTL: Baseline cost savings
   - Extended 1-hour TTL option: 12x improvement in cost efficiency
   - Ideal for long-running agent workflows

2. **Files API**
   - Upload documents once, reference repeatedly
   - Reduced per-request overhead
   - Efficient for document-heavy workflows

3. **Context Window Efficiency**
   - 1 million token context reduces API calls needed
   - Fewer context switches mean lower overall costs
   - Enables comprehensive codebase analysis in single request

---

## API Capabilities

### Code Execution Tool

**Functionality**: Executes Python code in a secure, sandboxed environment

**Capabilities**:

- Run arbitrary Python code safely
- Generate computational results
- Create data visualizations
- Clean and transform datasets
- Produce insights directly within API requests

**Use Cases**:

- Data analysis and transformation
- Visualization generation for reports
- Computational problem solving
- Automated testing and validation

**Limitations**:

- Python-only support
- Network access limited to approved services
- File system access restricted to temporary directories

### MCP Connector (Model Context Protocol)

**Functionality**: Connects Claude to remote MCP servers without custom client code

**Key Features**:

- Automatic connection management
- Tool discovery and loading
- Error handling managed by API
- Access to diverse third-party tool ecosystems
- No client-side coding required

**Benefits**:

- Immediate access to powerful integrations
- Extensible architecture for custom tools
- Simplified tool integration workflow
- Reduced maintenance burden

**Available MCP Servers**:

- File system operations
- Version control integration (Git)
- Database connectors
- Web browsing
- Custom application APIs

### Files API

**Functionality**: Simplified document storage and access

**Features**:

- Upload documents once
- Reference repeatedly across requests
- Automatic file lifecycle management
- Support for multiple file formats

**Supported File Types**:

- Text files (.txt, .md)
- Code files (.py, .js, .cpp, etc.)
- Documents (.pdf, .docx)
- Images (.png, .jpg, .jpeg)
- Data files (.csv, .json)

**Benefits**:

- Reduces file management overhead
- Streamlines long-running workflows
- Enables efficient document-heavy applications
- Lower token usage for repeated documents

### Extended Prompt Caching

**Functionality**: Cache prompts and responses for cost-efficient reuse

**Standard Caching**:

- Time to Live (TTL): 5 minutes
- Baseline cost savings
- Automatic cache management

**Extended Caching**:

- Time to Live (TTL): 1 hour
- 12x improvement over standard caching
- Ideal for long-running agent workflows
- Significant cost reduction for repetitive tasks

**Use Cases**:

- Multi-turn conversations with consistent context
- Batch processing with shared context
- Long-running development sessions
- Agent workflows with repeated reasoning

---

## Technical Specifications

### Model Information

**Primary Model**: Claude Sonnet 4

**Context Window**:

- **Size**: 1 million tokens (largest available as of 2025)
- **Equivalent to**: ~750,000 words
- **Code Examples**: 75,000+ lines of code
- **Literary Equivalent**: Entire "Lord of the Rings" trilogy

**Performance Characteristics**:

- **Input Processing**: Fast and efficient
- **Output Quality**: High-quality, nuanced responses
- **Code Generation**: Accurate and well-structured
- **Reasoning**: Deep, multi-step logical analysis

### Token Limits

| Tier | Input Tokens | Output Tokens | Context Window |
|------|--------------|---------------|----------------|
| Pro | Limited | Limited | 200K+ |
| Max | Extended | Extended | 1M |
| Team | Custom | Custom | 1M |

### Request Handling

- **Maximum Request Size**: 750,000 words equivalent
- **Concurrent Requests**: Depends on subscription tier
- **Rate Limiting**: Fair usage policies apply
- **Timeout**: Configurable, typical 5-30 minutes for long tasks

---

## Platform and Language Support

### SDK Support

**Available SDKs**:

1. **TypeScript SDK**
   - Full API support
   - Async/await pattern support
   - Type safety and IntelliSense
   - Framework integration examples

2. **Python SDK**
   - Complete API coverage
   - Synchronous and asynchronous support
   - Rich type hints
   - Integration with popular libraries

3. **Command-Line Interface (CLI)**
   - Direct API access from terminal
   - Scripting capabilities
   - Batch processing support
   - Environment variable configuration

### IDE Integration

**Supported Environments**:

- **JetBrains IDEs**
  - IntelliJ IDEA
  - PyCharm
  - WebStorm
  - CLion
  - GoLand
  - PhpStorm
  - RubyMine

- **Web Application**
  - Standalone browser interface
  - No IDE installation required
  - Accessible from any device

### Language Support (Code Analysis)

- **Primary**: C, C++, Python, JavaScript, TypeScript, Java
- **Extended**: Go, Rust, Ruby, PHP, C#, Swift, Kotlin
- **Web**: HTML, CSS, SCSS, Vue, React, Angular
- **Other**: SQL, Bash, Docker, YAML, JSON, XML

---

## Security and Integration

### Security Features

1. **API Access Control**
   - API key authentication
   - Token-based authorization
   - Scope-based permissions
   - Rate limiting and quotas

2. **Code Execution Sandboxing**
   - Isolated Python execution environment
   - No direct host system access
   - Restricted file system access
   - Network access limitations
   - Resource usage controls

3. **Data Protection**
   - Encrypted transmission (HTTPS)
   - Encryption at rest for stored data
   - Compliance with industry standards
   - GDPR compliance options

4. **Audit Trails**
   - Log all AI-driven code changes
   - Track API usage and requests
   - Team activity monitoring
   - Compliance reporting

5. **Team-Based Security**
   - Role-based access control (RBAC)
   - Organization-level permissions
   - Project isolation
   - Member management

### Integration Capabilities

1. **Version Control Integration**
   - Git repository cloning
   - Branch operations
   - Commit and pull request creation
   - Repository analysis

2. **Development Workflow Integration**
   - CI/CD pipeline integration
   - Testing framework integration
   - Build system support
   - Deployment automation

3. **Third-Party Tools**
   - MCP server connections
   - Custom tool integration
   - API endpoint connections
   - Database connectors

4. **Team Collaboration**
   - Shared workspace
   - Code review workflows
   - Comment and discussion
   - Change approval processes

---

## Agent Capabilities

### Multi-Step Task Handling

Claude Code can orchestrate complex, multi-step development tasks:

**Workflow Types**:

- Sequential task execution
- Parallel subtask handling
- Conditional branching
- Error recovery and retry logic
- Dynamic task adaptation

**Task Complexity**:

- Planning and strategy formulation
- Implementation and coding
- Testing and validation
- Documentation and refactoring
- Deployment and monitoring

### Feature Implementation

- **Scope Analysis**: Understand requirements and codebase impact
- **Design**: Propose architecture and implementation strategy
- **Implementation**: Write production-quality code
- **Testing**: Create comprehensive test cases
- **Integration**: Handle dependencies and imports
- **Documentation**: Generate API docs and guides

### Code Refactoring

- **Analysis**: Identify improvement opportunities
- **Planning**: Design refactoring strategy
- **Execution**: Apply transformations
- **Validation**: Ensure correctness and performance
- **Documentation**: Update relevant docs

### Code Review Automation

- **Static Analysis**: Identify code quality issues
- **Security Review**: Detect potential vulnerabilities
- **Performance Analysis**: Suggest optimizations
- **Style Checking**: Enforce code standards
- **Test Coverage**: Identify gaps in testing

### Complex Task Transformation

- Breaking down large projects into subtasks
- Managing dependencies and sequencing
- Handling cross-cutting concerns
- Coordinating multiple file changes
- Managing breaking changes

---

## Strengths

### Technical Strengths

1. **Largest Context Window in Industry**
   - 1 million tokens (as of 2025)
   - Enables comprehensive codebase analysis in single request
   - Reduces need for context switching
   - Supports entire projects as context

2. **Robust and Comprehensive API**
   - Code execution sandbox
   - MCP connector for extensibility
   - Files API for document management
   - Extended prompt caching
   - Well-documented SDK

3. **Advanced Cost Optimization**
   - Extended prompt caching (1-hour TTL)
   - Files API reduces per-request token usage
   - Efficient context window utilization
   - Cost-effective for long-running workflows

4. **MCP Connector Extensibility**
   - Direct connection to MCP servers
   - No custom client code required
   - Automatic tool discovery
   - Error handling by platform
   - Access to diverse tool ecosystems

5. **Strong Multi-Model Support**
   - Web application for quick access
   - IDE integration for native experience
   - SDK for programmatic access
   - CLI for automation and scripting

### Operational Strengths

6. **Enterprise-Grade Security**
   - Comprehensive audit trails
   - Role-based access control
   - Data encryption and protection
   - Compliance support
   - Team-based governance

7. **Deep IDE Integration**
   - Native JetBrains integration
   - Context-aware assistance
   - Seamless workflow integration
   - Multi-file editing support

8. **Code Execution Capability**
   - Transforms Claude from writer to analyst
   - Enables data visualization
   - Supports iterative development
   - Direct result generation

9. **Mature Agent Architecture**
   - Proven multi-step reasoning
   - Complex task coordination
   - Error recovery mechanisms
   - Adaptive task execution

### Market Strengths

10. **Proven Reliability**
    - Backed by Anthropic's research
    - Used in production environments
    - Strong community support
    - Regular feature updates

---

## Weaknesses and Limitations

### Access and Pricing

1. **Subscription-Required Model**
   - No free tier available
   - Monthly commitment required
   - Higher entry cost than some competitors
   - May not suit occasional users

2. **Lack of Usage-Based Pricing Option**
   - No pay-as-you-go pricing tier
   - Fixed subscription regardless of usage
   - Less flexible for variable workloads

### Technical Limitations

3. **Code Execution Constraints**
   - Python-only support (no C++, Java execution)
   - Limited network access
   - File system restrictions
   - No direct system command execution

4. **API Complexity**
   - Steeper learning curve than competitors
   - More configuration options required
   - Requires understanding of MCP for advanced features
   - SDK documentation could be more comprehensive

5. **Model Limitations**
   - Single model option (Claude Sonnet 4)
   - No option for smaller, faster models
   - No multi-model selection like Cursor or Windsurf

### Market Positioning

6. **Smaller IDE Integration Ecosystem**
   - JetBrains-focused (missing VSCode integration)
   - Smaller community of third-party integrations
   - Fewer plugin options compared to GitHub Copilot or Cursor
   - Limited extension marketplace

7. **Less Mature Integration Marketplace**
   - Fewer pre-built integrations than competitors
   - Smaller ecosystem of MCP servers available
   - Limited template and recipe availability
   - Newer integration standards

8. **Market Presence**
   - Newer to market than GitHub Copilot
   - Smaller installed user base
   - Fewer case studies and testimonials
   - Less brand recognition outside tech circles

### Community and Resources

9. **Community Size**
   - Smaller user community than Copilot or Cursor
   - Fewer online tutorials and guides
   - Less Stack Overflow coverage
   - Emerging ecosystem

---

## Use Cases

### Ideal Use Cases

1. **Enterprise Development Teams**
   - Need for security and audit trails
   - Requirement for team collaboration
   - Large codebase management
   - Complex multi-step development tasks

2. **Data Science and Analysis**
   - Code execution for data transformation
   - Visualization generation
   - Statistical analysis
   - Jupyter notebook integration

3. **Large-Scale Refactoring Projects**
   - Multi-file coordinated changes
   - Architectural improvements
   - Dependency management
   - Test coverage improvement

4. **Code Review and Quality**
   - Automated code analysis
   - Security scanning
   - Performance optimization
   - Documentation generation

5. **Cross-File Feature Development**
   - Understanding large codebases
   - Implementing features across multiple files
   - Managing dependencies
   - Consistent API design

6. **Advanced Integration Requirements**
   - Custom MCP server integration
   - Specialized tool connections
   - Workflow automation
   - Legacy system integration

### Less Suitable Use Cases

- **Budget-Conscious Individual Developers** (No free tier)
- **Lightweight Coding Tasks** (Overkill for simple completions)
- **Fast Code Snippets** (Heavier than lightweight tools)
- **Non-JetBrains IDE Users** (Limited IDE support)
- **Python Code Execution** (Code running requirements)

---

## Integration Guide

### Getting Started with Claude Code

#### Step 1: Subscribe to Claude

1. Visit [claude.ai](https://claude.ai)
2. Choose subscription tier:
   - **Pro** ($20/month) for individual developers
   - **Max** ($100/month) for power users
   - **Team** (custom pricing) for organizations

#### Step 2: Access Claude Code

**Via Web Application**:

1. Log in to Claude website
2. Access Claude Code from menu
3. Start writing code or upload files

**Via JetBrains IDE**:

1. Install Claude Code plugin from JetBrains marketplace
2. Configure API authentication
3. Select subscription tier
4. Start using inline assistance

**Via SDK**:

1. Install TypeScript or Python SDK
2. Configure API key from account settings
3. Initialize client
4. Start making API calls

#### Step 3: Configure Your Environment

**API Key Setup**:

```bash
export ANTHROPIC_API_KEY="your-api-key-here"
```

**Environment Configuration**:

```json
{
  "model": "claude-sonnet-4",
  "max_tokens": 4096,
  "temperature": 0.7
}
```

### SDK Integration Examples

#### Python Integration

```python
from anthropic import Anthropic

client = Anthropic(api_key="your-api-key")

response = client.messages.create(
    model="claude-sonnet-4",
    max_tokens=2048,
    messages=[
        {
            "role": "user",
            "content": "Help me refactor this Python code for better performance"
        }
    ]
)

print(response.content[0].text)
```

#### TypeScript Integration

```typescript
import Anthropic from "@anthropic-ai/sdk";

const client = new Anthropic({
  apiKey: process.env.ANTHROPIC_API_KEY,
});

async function analyzeCode(code: string) {
  const response = await client.messages.create({
    model: "claude-sonnet-4",
    max_tokens: 2048,
    messages: [
      {
        role: "user",
        content: `Review this code for security issues:\n\n${code}`,
      },
    ],
  });

  return response.content[0].type === "text" ? response.content[0].text : "";
}
```

### Files API Integration

```python
# Upload a file
with open("myfile.py", "rb") as f:
    file_response = client.beta.files.upload(
        file=("myfile.py", f, "text/plain"),
    )
    file_id = file_response.id

# Use the file in messages
response = client.messages.create(
    model="claude-sonnet-4",
    max_tokens=2048,
    messages=[
        {
            "role": "user",
            "content": [
                {
                    "type": "document",
                    "source": {
                        "type": "file",
                        "file_id": file_id,
                    },
                },
                {
                    "type": "text",
                    "text": "Analyze this code for bugs"
                }
            ],
        }
    ],
)
```

### MCP Connector Integration

```python
# Connect to an MCP server
response = client.messages.create(
    model="claude-sonnet-4",
    max_tokens=2048,
    tools=[
        {
            "type": "mcp",
            "mcp_server_url": "http://your-mcp-server:3000"
        }
    ],
    messages=[
        {
            "role": "user",
            "content": "Use the available tools to analyze the git repository"
        }
    ]
)
```

---

## Comparison with Competitors

### Claude vs GitHub Copilot

| Feature | Claude | Copilot |
|---------|--------|---------|
| **Pricing** | $20-100/month | Free, $10-39/month |
| **Context Window** | 1M tokens | 32K-128K tokens |
| **IDE Support** | JetBrains, Web | VS Code, JetBrains, Web |
| **Code Execution** | Yes (Python) | No |
| **Free Tier** | No | Yes |
| **Enterprise Features** | Advanced | Yes |
| **MCP Support** | Yes | No |
| **Market Position** | Premium/Enterprise | Mainstream |

### Claude vs Cursor

| Feature | Claude | Cursor |
|---------|--------|--------|
| **Pricing** | $20-100/month | Free/$20/month |
| **IDE Type** | Integration/Web | Native IDE |
| **Model Flexibility** | Claude only | Multiple models |
| **Code Execution** | Yes | Limited |
| **Context Window** | 1M tokens | 200K tokens |
| **IDE Integration** | Deep (JetBrains) | Native (VSCode-based) |

### Claude vs Google Gemini Code Assist

| Feature | Claude | Gemini |
|---------|--------|--------|
| **Pricing** | $20-100/month | Free (180K/month limit) |
| **Context Window** | 1M tokens | Varies |
| **Google Integration** | No | Yes (Android, GCP) |
| **Free Usage** | No | Yes |
| **Code Execution** | Yes | Limited |
| **Enterprise Features** | Advanced | Limited |

### Claude vs Amazon Q Developer

| Feature | Claude | Amazon Q |
|---------|--------|-----------|
| **Pricing** | $20-100/month | $19/user/month |
| **AWS Integration** | Limited | Deep (AWS-native) |
| **Code Execution** | Yes | Limited |
| **Security Scanning** | Manual | Built-in |
| **Context Window** | 1M tokens | 100K tokens |
| **Target Audience** | General/Enterprise | AWS-focused |

---

## Best Practices

### Code Quality and Security

1. **Leverage Large Context Window**
   - Upload entire codebase for comprehensive analysis
   - Let Claude understand project architecture
   - Enable cross-file consistency checks
   - Improve refactoring accuracy

2. **Use Code Execution for Validation**
   - Test generated code immediately
   - Verify data transformations
   - Generate visualizations
   - Validate mathematical operations

3. **Implement Code Review Workflows**
   - Use Claude for initial automated review
   - Check security issues proactively
   - Verify performance implications
   - Validate test coverage

4. **Document with Claude**
   - Generate API documentation
   - Create code comments
   - Write integration guides
   - Maintain architecture documentation

### API Usage Optimization

5. **Maximize Extended Prompt Caching**
   - Reuse context for related tasks
   - Share codebase context across requests
   - Cache frequently accessed files
   - Reduce token consumption by 12x

6. **Use Files API Effectively**
   - Upload large files once
   - Reference repeatedly
   - Reduce per-request overhead
   - Manage document lifecycle

7. **Optimize Model Selection**
   - Use Claude Sonnet 4 for general tasks
   - Consider Max tier for intensive workloads
   - Monitor token usage
   - Right-size subscription tier

### Team and Enterprise Practices

8. **Implement Access Controls**
   - Use role-based permissions
   - Restrict sensitive operations
   - Audit AI-driven changes
   - Maintain compliance trails

9. **Establish Workflows**
   - Create code review processes
   - Define approval workflows
   - Document standards
   - Monitor adoption

10. **Security Hardening**
    - Never expose API keys
    - Use environment variables
    - Rotate credentials regularly
    - Enable audit logging
    - Implement rate limiting

---

## Resources and Links

### Official Documentation

- **Claude Documentation**: <https://docs.anthropic.com/>
- **Claude Code Launch**: <https://www.anthropic.com/news/claude-code>
- **API Reference**: <https://docs.anthropic.com/api/>

### SDK and Tools

- **Python SDK**: <https://github.com/anthropics/anthropic-sdk-python>
- **TypeScript SDK**: <https://github.com/anthropics/anthropic-sdk-js>
- **Playground**: <https://claude.ai>

### Integration Resources

- **MCP Protocol**: <https://modelcontextprotocol.io/>
- **JetBrains Integration**: <https://www.jetbrains.com/help/idea/ai-assistant.html>
- **Files API Guide**: <https://docs.anthropic.com/en/docs/build-a-system-prompt-with-the-files-api>

### Community and Support

- **GitHub Discussions**: <https://github.com/anthropics/anthropic-sdk-python/discussions>
- **Twitter/X Updates**: @anthropic
- **Blog**: <https://www.anthropic.com/news>

### Competitive Comparisons

- **AI Coding Tools Market**: Research reports on AI coding assistant adoption
- **Benchmarks**: LLM code generation benchmarks (HumanEval, MBPP)
- **Performance Metrics**: Claude's performance on standard coding benchmarks

### Learning Resources

- **Tutorials**: Starter guides and walkthroughs
- **Examples**: Real-world usage examples and patterns
- **Best Practices**: Optimization and usage guides
- **Case Studies**: Enterprise implementation stories

---

## Conclusion

Claude Code represents a premium, feature-rich AI coding assistant designed for teams and enterprises prioritizing comprehensive codebase understanding, security, and advanced capabilities. Its 1 million token context window, robust API, code execution sandbox, and strong security features make it an excellent choice for:

- **Large-scale development projects**
- **Enterprise teams** requiring audit trails and access control
- **Complex refactoring initiatives**
- **Data science and analysis workflows**
- **Security-focused organizations**

However, the subscription-only model without a free tier, limited IDE support (JetBrains-focused), and higher pricing make it less accessible for budget-conscious or casual developers. The choice between Claude and competitors like GitHub Copilot, Cursor, or Google Gemini Code Assist should consider:

1. Your team size and budget constraints
2. IDE preferences and existing workflows
3. Security and compliance requirements
4. Need for code execution capabilities
5. Importance of context window size
6. Availability of free or low-cost alternatives

For organizations that can leverage its full feature set and justify the premium pricing, Claude Code is a powerful investment in AI-assisted development capabilities.

---

**Document Version**: 1.0
**Last Updated**: November 2025
**Applies to**: Claude Code (2025 Release)
