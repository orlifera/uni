# Build

```bash
sudo docker build -t registry.insecurity-insa.fr/insecurity/xoring .
```

# Run

```bash
sudo docker run registry.insecurity-insa.fr/insecurity/xoring

sudo docker stop xoring && docker rm -v xoring
sudo docker exec -u 0 -it xoring bash
```
