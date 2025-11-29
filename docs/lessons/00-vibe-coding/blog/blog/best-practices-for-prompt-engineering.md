以下是为您重新排版的内容。我使用了 Markdown 的多种特性（如代码块、引用、表格、层级标题和 emoji）来增强可读性和视觉美感，使其不仅结构清晰，而且便于查阅。

-----

# 🚀 Best Practices for Prompt Engineering

### Get better AI results with prompt engineering techniques from the team behind Claude

> 🏷️ **Category:** Agents  |  📱 **Product:** Claude apps  |  📅 **Date:** November 10, 2025  |  ⏱️ **Reading time:** 5 min

-----

**Context engineering** has emerged as an increasingly important part of working with LLMs, with prompt engineering as its essential building block.

**Prompt engineering** is the craft of structuring instructions to get better outputs from AI models. It's how you phrase queries, specify style, provide context, and guide the model's behavior to achieve your goals.

* **The Gap:** The difference between a vague instruction and a well-crafted prompt can mean the gap between generic outputs and exactly what you need.
* **The Goal:** A well-engineered prompt gets you there in one shot, avoiding multiple back-and-forth exchanges.

-----

## 🧱 Core Techniques

These techniques form the foundation of effective AI interactions. Use them consistently for immediate improvements.

### 1\. Be Explicit and Clear

Modern AI models respond exceptionally well to clear instructions. Don't assume the model will infer what you want—state it directly.

* **Key Principle:** Tell the model exactly what you want to see. If you want specific features, list them.

**Example: Creating an analytics dashboard**

| ❌ Vague | ✅ Explicit |
| :--- | :--- |
| "Create an analytics dashboard" | "Create an analytics dashboard. Include as many relevant features and interactions as possible. Go beyond the basics to create a fully-featured implementation." |

**Best practices:**

* Lead with direct action verbs: "Write," "Analyze," "Generate," "Create".
* Skip preambles and get straight to the request.
* State what you want the output to **include**, not just what to work on.
* Be specific about quality and depth expectations.

### 2\. Provide Context and Motivation

Explaining **why** something matters helps AI models deliver targeted responses.

**Example: Formatting preferences**

> **Less effective:** "NEVER use bullet points"
>
> **More effective:** "I prefer responses in natural paragraph form rather than bullet points because I find flowing prose easier to read and more conversational. Bullet points feel too formal and list-like for my casual learning style."

**When to provide context:**

* Explaining the purpose or audience.
* Clarifying constraints.
* Describing usage.
* Indicating the problem you are solving.

### 3\. Be Specific

Structure instructions with explicit guidelines. The more specific, the better.

**Example: Meal planning**

* **Vague:** "Create a meal plan for a Mediterranean diet"
* **Specific:** "Design a Mediterranean diet meal plan for pre-diabetic management. 1,800 calories daily, emphasis on low glycemic foods. List breakfast, lunch, dinner, and one snack with complete nutritional breakdowns."

### 4\. Use Examples (Few-Shot Prompting)

Examples show rather than tell, clarifying subtle requirements like tone or format.

**Example: Article Summarization**

```text
Here's an example of the summary style I want:
Article: [link to article about AI regulation]
Summary: EU passes comprehensive AI Act targeting high-risk systems. Key provisions include transparency requirements and human oversight mandates. Takes effect 2026.

Now summarize this article in the same style: [link to your new article]
```

> 💡 **Pro tip:** Start with one example (one-shot). Only add more (few-shot) if the output needs refinement.

### 5\. Give Permission to Express Uncertainty

Reduce hallucinations by explicitly allowing the AI to say "I don't know."

**Example:**

> "Analyze this financial data and identify trends. **If the data is insufficient to draw conclusions, say so rather than speculating.**"

-----

## 🧪 Advanced Techniques

Use these for building agentic solutions, complex data structures, or multi-stage problems.

### 1\. Prefill the AI's Response

Start the AI's response for it to guide format or skip preambles.

**Example: Enforcing JSON output**

```python
messages=[
    {"role": "user", "content": "Extract the name and price from this product description into JSON."},
    {"role": "assistant", "content": "{"}
]
```

*The AI will continue from `{`, outputting valid JSON.*

### 2\. Chain of Thought (CoT) Prompting

Request step-by-step reasoning before the final answer.
*Note: Claude's **extended thinking** feature automates this, but manual CoT is useful when that isn't available.*

* **Basic CoT:** Add "Think step-by-step" to your instructions.
* **Guided CoT:** Tell it specific reasoning stages (First think about X, then consider Y, finally write Z).
* **Structured CoT:** Use tags to separate reasoning from the answer.

    ```xml
    Think before you write the email in <thinking> tags.
    Then write the email in <email> tags.
    ```

### 3\. Control the Output Format

* **Tell the AI what TO do:** Instead of "No markdown," say "Use smoothly flowing prose."
* **Match prompt style:** If you want minimal markdown, use minimal markdown in your prompt.
* **Be explicit:**
    > "DO NOT use ordered lists... incorporate items naturally into sentences."

### 4\. Prompt Chaining

Break complex tasks into sequential steps with separate prompts (trading latency for accuracy).

1. **Prompt 1:** "Summarize this paper..."
2. **Prompt 2:** "Review the summary above for accuracy..."
3. **Prompt 3:** "Improve the summary based on feedback..."

-----

## 📜 Legacy Techniques (Use Sparingly)

Some older techniques are less necessary with modern models like Claude 3.5/4.x.

* **XML Tags:** Still useful for very complex prompts to define boundaries (e.g., `<athlete_info>...</athlete_info>`), but modern models usually understand structure without them.
* **Role Prompting:** "You are a generic expert" is often less effective than specific instructions.
  * *Instead of:* "You are a financial advisor."
  * *Try:* "Analyze this portfolio focusing on risk tolerance and long-term growth."

-----

## 🧩 Putting It All Together

The real power emerges when you combine techniques.

**Example: Composite Prompt**

```text
Extract key financial metrics from this quarterly report and present them in JSON format.

I need this data for automated processing, so it's critical that your response contains ONLY valid JSON with no preamble or explanation.

Use this structure:
{
  "revenue": "value with units",
  "profit_margin": "percentage",
  "growth_rate": "percentage"
}

If any metric is not clearly stated in the report, use null rather than guessing.

Begin your response with an opening brace: {
```

**Techniques used:**
✅ Explicit instructions
✅ Context (automated processing)
✅ Example structure
✅ Permission to be uncertain (use null)
✅ Prefilling (begin with brace)

-----

## 🧭 Decision Framework: Which technique to use?

**Start here:** Is your request clear? If no, fix clarity first.

| If you need... | Use... |
| :--- | :--- |
| **Specific output format** | Examples, prefilling, or explicit format instructions |
| **Step-by-step reasoning** | Extended thinking (Claude 4.x) or Chain of Thought |
| **Complex multi-stage task** | Prompt Chaining |
| **Transparent reasoning** | Chain of Thought with structured output |
| **To prevent hallucinations** | Permission to say "I don't know" |

-----

## 🔧 Troubleshooting & Common Mistakes

### Troubleshooting

* **Response too generic?** → Add specificity, examples, ask to "go beyond basics."
* **Misses the point?** → Provide context on *why* you are asking.
* **Inconsistent format?** → Use One-shot/Few-shot examples or prefilling.
* **Task too complex?** → Break into chains.
* **Too much preamble?** → Use prefilling or explicitly say "Skip preamble."
* **Hallucinations?** → Give permission to be uncertain.

### Mistakes to Avoid

* 🚫 **Don't over-engineer:** Longer isn't always better.
* 🚫 **Don't ignore basics:** Clarity is king.
* 🚫 **Don't assume mind-reading:** Be specific.
* 🚫 **Don't use everything at once:** Select only what solves the problem.
* 🚫 **Don't forget to iterate:** Test and refine.

-----

## 📝 Final Words

Prompt engineering is about communication. The best prompt isn't the most complex one; it's the one that achieves your goals reliably with the minimum necessary structure.

> **Context Awareness Note:** Modern models handle long context well, but **task-splitting** is still valuable. It helps the model focus on a specific scope, producing higher quality results than a massive "do everything" prompt.

Start with core techniques. Only layer in advanced methods when needed.

**[anthropic.skilljar.com](https://anthropic.skilljar.com)** - Check out the prompt engineering course to measure your effectiveness.
