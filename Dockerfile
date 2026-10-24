FROM python:3.10-slim
RUN apt-get update && apt-get install -y g++ --no-install-recommends && rm -rf /var/lib/apt/lists/*
WORKDIR /app
RUN pip install flask
COPY . /app
EXPOSE 5000
CMD ["python", "app.py"]
