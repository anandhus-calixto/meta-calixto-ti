SUMMARY = "Calixto Custom Default Image"
DESCRIPTION = "Based on Arago TI SDK"

# Pull in everything from the TI base image
require recipes-core/images/tisdk-default-image.bb

# Override the image name (This changes the .tar.xz / .wic filename)
export IMAGE_BASENAME = "calixto-default-image"

# Optional: Add specific packages only for your custom image
IMAGE_INSTALL:append = " htop bash"
