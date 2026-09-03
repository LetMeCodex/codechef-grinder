import os
from pathlib import Path
from pydantic import BaseModel, Field

class BotConfig(BaseModel):
    # API & Session Credentials
    gemini_api_key: str = Field(default_factory=lambda: os.getenv("GEMINI_API_KEY", ""))
    gemini_model: str = Field(default_factory=lambda: os.getenv("GEMINI_MODEL", "gemini-2.5-flash"))
    codechef_session: str = Field(default_factory=lambda: os.getenv("CODECHEF_SESSION", ""))
    
    # Execution & Grinding Settings
    language: str = Field(default_factory=lambda: os.getenv("LANGUAGE", "cpp"))  # "cpp" or "python3"
    problems_per_run: int = Field(default_factory=lambda: int(os.getenv("PROBLEMS_PER_RUN", "3")))
    max_retries: int = Field(default_factory=lambda: int(os.getenv("MAX_RETRIES", "3")))
    submission_delay_seconds: int = Field(default_factory=lambda: int(os.getenv("SUBMISSION_DELAY_SECONDS", "30")))
    
    # Difficulty Range (Ladder Progression)
    min_difficulty: int = Field(default_factory=lambda: int(os.getenv("MIN_DIFFICULTY", "200")))
    max_difficulty: int = Field(default_factory=lambda: int(os.getenv("MAX_DIFFICULTY", "1400")))
    
    # File Paths
    data_file: Path = Field(default_factory=lambda: Path(os.getenv("DATA_FILE", "data/solved_problems.json")))
    solutions_dir: Path = Field(default_factory=lambda: Path(os.getenv("SOLUTIONS_DIR", "solutions")))
    
    # Dry Run Mode (Generates code and validates locally, avoids live submission)
    dry_run: bool = Field(default_factory=lambda: os.getenv("DRY_RUN", "false").lower() in ("true", "1", "yes"))

config = BotConfig()
