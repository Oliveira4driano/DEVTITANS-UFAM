# Herda as configurações do emulador (produto sdk_phone_x86_64)
$(call inherit-product, $(SRC_TARGET_DIR)/product/sdk_phone_x86_64.mk)

# Sobrescreve algumas variáveis com os dados do novo produto
PRODUCT_NAME := devtitans_carbosensor
PRODUCT_DEVICE := carbosensor
PRODUCT_BRAND := carbosensorBrand
PRODUCT_MODEL := carbosensorModel

# Copia o arquivo devtitans.txt para o /system/etc da imagem do Android
PRODUCT_COPY_FILES += \
	device/devtitans/carbosensor/carbosensor.rc:vendor/etc/init/carbosensor.rc \
	device/devtitans/carbosensor/bootanimation.zip:product/media/bootanimation.zip

PRODUCT_SYSTEM_PROPERTIES += \
    ro.devtitans.name=CarboSensor

PRODUCT_PRODUCT_PROPERTIES += \
    ro.product.devtitans.version=1.0

PRODUCT_VENDOR_PROPERTIES += \
    ro.vendor.devtitans.hardware=ModelB

# Seta o diretório de overlays
PRODUCT_PACKAGE_OVERLAYS = device/devtitans/carbosensor/overlay

PRODUCT_PACKAGES += \
    UniversalMediaPlayer

# Carbosensor AIDL Interface
PRODUCT_PACKAGES += devtitans.carbosensor

# Carbosensor Binder Service
PRODUCT_PACKAGES += devtitans.carbosensor-service

# Device Framework Matrix (Declara que o nosso produto Kraken precisa do serviço carbosensor)
DEVICE_FRAMEWORK_COMPATIBILITY_MATRIX_FILE := device/devtitans/carbosensor/device_framework_matrix.xml

# Manager
PRODUCT_PACKAGES += devtitans.carbosensormanager
    
BOARD_SEPOLICY_DIRS += device/devtitans/carbosensor/sepolicy
