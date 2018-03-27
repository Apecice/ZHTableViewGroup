//
//  ZHAutoConfigurationCollectionViewDelegate.m
//  Pods
//
//  Created by 张行 on 2017/4/20.
//
//

#import "ZHAutoConfigurationCollectionViewDelegate.h"
#import "ZHCollectionViewDataSource.h"

@implementation ZHAutoConfigurationCollectionViewDelegate {
    ZHCollectionViewDataSource *_dataSource;
}

- (instancetype)initWithDataSource:(ZHCollectionViewDataSource *)dataSource {
    if (self = [super init]) {
        _dataSource = dataSource;
    }
    return self;
}

- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView *)collectionView {
    return [ZHCollectionViewDataSource numberOfSectionsWithDataSource:_dataSource];
}

- (__kindof UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath {
    return [ZHCollectionViewDataSource cellForRowAtWithDataSource:_dataSource indexPath:indexPath];
}

- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section {
    return [ZHCollectionViewDataSource numberOfRowsInSectionWithDataSource:_dataSource section:section];
}

- (UICollectionReusableView *)collectionView:(UICollectionView *)collectionView viewForSupplementaryElementOfKind:(NSString *)kind atIndexPath:(NSIndexPath *)indexPath {
    if ([kind isEqualToString:UICollectionElementKindSectionHeader]) {
        return [ZHCollectionViewDataSource viewForHeaderInSectionWithDataSource:_dataSource section:indexPath.section];
    } else {
        return [ZHCollectionViewDataSource viewForFooterInSectionWithDataSource:_dataSource section:indexPath.section];
    }
}

- (void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath {
    [collectionView deselectItemAtIndexPath:indexPath animated:YES];
    [ZHCollectionViewDataSource didSelectRowAtWithDataSource:_dataSource indexPath:indexPath];
}

- (CGSize)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout*)collectionViewLayout sizeForItemAtIndexPath:(NSIndexPath *)indexPath {
    return [ZHCollectionViewDataSource sizeForItemWithDataSource:_dataSource indexPath:indexPath];
}

- (CGSize)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout*)collectionViewLayout referenceSizeForHeaderInSection:(NSInteger)section {
    return [ZHCollectionViewDataSource referenceSizeForHeaderFooterWithDataSource:_dataSource style:ZHCollectionViewHeaderFooterStyleHeader section:section];
}

- (CGSize)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout referenceSizeForFooterInSection:(NSInteger)section {
    return [ZHCollectionViewDataSource referenceSizeForHeaderFooterWithDataSource:_dataSource style:ZHCollectionViewHeaderFooterStyleFooter section:section];
}

@end

