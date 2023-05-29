from setuptools import setup

package_name = 'pubsub_demo'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='grantli',
    maintainer_email='2190315392@qq.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'publisher = pubsub_demo.publisher_member_function:main',
            'subscriber = pubsub_demo.subscriber_member_function:main'
        ],
    },
)
