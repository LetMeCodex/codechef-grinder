# 👨‍🍳 CodeChef Practice Archive Auto-Grinder (500+ Solved Scaler)

An autonomous, serverless bot designed to grind through the CodeChef Practice Archive, solving 5 to 10 problems daily via **GitHub Actions** to push your **"Problems Solved"** counter to 500+ and beyond!

Powered by **Gemini Multi-Model AI** (C++17 & Python 3) with dynamic CSRF extraction, automated ladder progression (from rating 200 up to 1400+), and a self-healing reflection loop.

---

## ⚡ Highlights

- 🎯 **Scale to 500+ Solved**: Solves 4 to 8 problems per day automatically on GitHub Actions cron (surpasses 500+ solved in under 2 months!).
- 🛡️ **0% MOSS / Plagiarism Risk**: Operates strictly on CodeChef's public Practice Archive (where solutions and editorials are open), meaning zero risk of contest penalties or bans.
- ⚡ **Dynamic CSRF Extraction**: Automatically parses dynamic `window.csrfToken` from problem pages on the fly.
- 🔄 **Self-Healing Reflection Loop**: If a solution receives *Wrong Answer* (WA) or *Time Limit Exceeded* (TLE), the bot diagnoses the failure, refactors the code, and re-submits (up to 3 attempts).
- 💾 **Local Persistent Tracking**: Maintains a JSON database (`data/solved_problems.json`) so it never repeats already solved problems.

---

## 🛠️ Step-by-Step Setup Guide

### Step 1: Push / Fork this Repository to GitHub
Create a new repository on your GitHub account (e.g. `codechef-bot` or `codechef-grinder`) and push this codebase:

```bash
git init
git branch -M main
git remote add origin https://github.com/<your-username>/<your-repo-name>.git
git add .
git commit -m "feat: initial release of codechef auto-grinder"
git push -u origin main
```

### Step 2: Grab Your CodeChef Session Cookie (`CODECHEF_SESSION`)
1. Open [codechef.com](https://www.codechef.com) and log in to your account.
2. Press `F12` (or right-click → **Inspect**) to open Developer Tools.
3. Go to the **Application** tab (or **Storage** in Firefox).
4. Under **Cookies**, click `https://www.codechef.com`.
5. Look for the cookie starting with `SESS` (e.g., `SESS93b6022d778ee317bf48f7dbffe03173`).
6. Copy its **Value** (or copy the whole `SESS...=value` string).

### Step 3: Add GitHub Secrets
In your GitHub repository:
1. Go to **Settings** → **Secrets and variables** → **Actions**.
2. Click **New repository secret** and add:
   - `GEMINI_API_KEY`: Your Gemini API key from [Google AI Studio](https://aistudio.google.com/).
   - `CODECHEF_SESSION`: Your CodeChef session cookie from Step 2.

### Step 4: Enable Workflow Write Permissions
For GitHub Actions to auto-commit solutions to your repository:
1. Go to **Settings** → **Actions** → **General**.
2. Under **Workflow permissions**, select **"Read and write permissions"**.
3. Click **Save**.

---

## 🧪 Testing & Execution

### 1. Manual One-Click Trigger from GitHub Actions
Go to your repo's **Actions** tab → Click **CodeChef Practice Auto-Grinder** on the left → Click **Run workflow**!

### 2. Local Dry Run (Without Submitting to CodeChef)
```bash
set DRY_RUN=true
set GEMINI_API_KEY="your-gemini-key"
python -m src.runner
```

---

## 📁 Repository Structure

```
codechef-autonomous-bot/
├── .github/
│   └── workflows/
│       └── daily_grind.yml       # Runs twice daily on cron (04:00 & 16:00 UTC)
├── data/
│   └── solved_problems.json      # Persistent tracker of solved problem codes
├── src/
│   ├── config.py                 # Pydantic configuration & difficulty bounds
│   ├── codechef_client.py        # Problem fetcher, CSRF extractor, submission API
│   ├── solver.py                 # Gemini CP engine with multi-model fallback & retry
│   └── runner.py                 # Batch grinder orchestrating discovery, solving & pacing
├── solutions/                    # Auto-committed C++ solutions by problem code
│   └── START01/
│       ├── solution.cpp
│       └── README.md
├── tests/
│   └── test_codechef_bot.py      # Automated component tests
├── requirements.txt
└── README.md
```
