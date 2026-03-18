SUMMARY = "Calixto Custom Tiny Image"
DESCRIPTION = "Based on Arago TI SDK"

# Pull in everything from the TI base image
require recipes-core/images/tisdk-tiny-image.bb

# Override the image name (This changes the .tar.xz / .wic filename)
export IMAGE_BASENAME = "calixto-tiny-image"

# Optional: Add specific packages only for your custom image
IMAGE_INSTALL:append = " tree alsa-utils-aplay alsa-utils-amixer alsa-utils-speakertest alsa-state"
